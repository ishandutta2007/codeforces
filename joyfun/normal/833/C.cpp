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

const int B = 10 , N = 19;
ll L , R;
int cnt[B],a[B],ans,lft[N],rgt[N];
void divide(ll x,int *a){
    rep(i,0,N) a[i]=x%B,x/=B;
}
inline bool check(int x,int l,int r){
    if(l>r) return 0;
    return (x&((1<<(r+1))-1))>>l;
}
int cal(){
    memcpy(a,cnt,sizeof(a));
    int s=0;
    rep(i,0,B) if(a[i]) s|=1<<i;
    bool away=false,err=false;
    per(i,0,N) {
        if(check(s,lft[i]+1,away?9:rgt[i]-1)) return 1;
        if(!a[lft[i]]) {err=true;break;}
        if(!--a[lft[i]]) s^=1<<lft[i];
        away|=lft[i]!=rgt[i];
    }
    if(!err) return 1;
    memcpy(a,cnt,sizeof(a));
    s=0;
    rep(i,0,B) if(a[i]) s|=1<<i;
    away=false,err=false;
    per(i,0,N) {
        if(check(s,away?0:lft[i]+1,rgt[i]-1)) return 1;
        if(!a[rgt[i]]) {err=true;break;}
        if(!--a[rgt[i]]) s^=1<<rgt[i];
        away|=lft[i]!=rgt[i];
    }
    if(!err) return 1;
    return 0;
}

void dfs(int c,int remain){
    if(c == 9){
        cnt[c] = remain;
        ans += cal();
    } else rep(i,0,remain+1) cnt[c]=i,dfs(c+1,remain-i);
}

int main(){
    cin >> L >> R;
    divide(L,lft);
    divide(R,rgt);
    ans = 0;
    dfs(0 , 19);
    cout << ans << endl;
    return 0;
}