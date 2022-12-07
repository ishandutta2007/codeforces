// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

const int N = 35035 , NODE = N * 50;
int n,K,a[N],f[55][N];
set<int> S;

int ls[NODE],rs[NODE],sum[NODE],h[N],_;
int newnode(){++_;ls[_]=rs[_]=sum[_]=0;return _;}
void ins(int &c,int l,int r,int x,int d){
    int p=newnode();
    sum[p]=sum[c]+d;
    ls[p]=ls[c];rs[p]=rs[c];
    c=p;
    if(l == r) return ;
    int mid=(l+r)>>1;
    if(x <= mid) ins(ls[c],l,mid,x,d);
    else ins(rs[c],mid+1,r,x,d);
}
int query(int c,int l,int r,int L,int R){
    if(c == 0) return 0;
    if(L <= l && r <= R) return sum[c];
    int mid=(l+r)>>1,ret=0;
    if(L <= mid) ret+=query(ls[c],l,mid,L,R);
    if(R > mid) ret+=query(rs[c],mid+1,r,L,R);
    return ret;
}
int ask=0,pos=0;
void query(int c,int l,int r){
    if(c == 0){
        return;
    }
    if(l == r){
        ask = sum[c];
        return;
    }
    int mid=(l+r)>>1;
    if(pos <= mid) query(ls[c],l,mid);
    else query(rs[c],mid+1,r);
}

inline int Cost(int l,int r){
    return query(h[r] , 1 , n , l , r);
}

void Dp(int i,int l,int r,int optl,int optr){
    if(l > r) return ;
    int m=(l+r)>>1 , opt = optl;
    int to = min(m - 1 , optr);
    int cost=0;
    if(to + 2 <= m) cost+=query(h[m],1,n,to+2,m);
    for(int j=to;j>=optl;--j){
        ask=0,pos=j+1;query(h[m],1,n);
        int tmp = f[i-1][j] + (cost += ask);
        if(tmp > f[i][m]){
            f[i][m] = tmp;
            opt = j;
        }
    }
    Dp(i , l , m - 1 , optl , opt);
    Dp(i , m + 1 , r , opt , optr);
}

int main(){
    scanf("%d%d",&n,&K);
    rep(i,1,n+1) scanf("%d",a + i);
    int *f=::f[1];
    set<int> S;
    map<int,int> pos;
    rep(i,1,n+1){
        h[i] = h[i-1];
        S.insert(a[i]);
        f[i] = sz(S);
        if(pos.count(a[i])) ins(h[i],1,n,pos[a[i]],-1);
        ins(h[i],1,n,pos[a[i]]=i,1);
        //cout << query(h[i],1,n,1,i) << endl;
    }
    rep(i,2,K+1) Dp(i , 1 , n , 0 , n);
    printf("%d\n",::f[K][n]);
    return 0;
}