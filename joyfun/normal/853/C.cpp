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

const int N = 2e5 + 10;
int n,Q,x[N],y[N];
ll c2(int n){
    return 1ll * n * (n - 1) / 2;
}
struct Query{
    int l,d,r,u;
    ll ans;
    void read(){
        scanf("%d%d%d%d",&l,&d,&r,&u);
        ans=c2(n)-c2(l-1)-c2(d-1)-c2(n-r)-c2(n-u);
    }
    void rot(){

    }
}q[N];
template<class T>
struct Fenwick{
#define lb(x) ((x)&-(x))
    int n;T a[N];
    void ini(int _n){ fill_n(a+1,n=_n,0);}
    void add(int x,T d){ for(;x<=n;x+=lb(x)) a[x]+=d;}
    T sum(int x){ T r=0;for(;x>=1;x^=lb(x)) r+=a[x];return r;}
};
Fenwick<int> fen;

vector<pii> ask[N];
int a[N];
int main(){
    scanf("%d%d",&n,&Q);
    rep(i,1,n+1) scanf("%d",y + i) , x[i] = i;
    rep(i,0,Q) q[i].read();
    rep(i,0,4){
        rep(i,1,n+1) {
            swap(x[i],y[i]);
            x[i]=n+1-x[i];
            a[x[i]] = y[i];
            ask[i].clear();
        }
        rep(i,0,Q){
            int l=q[i].l,r=q[i].r,d=q[i].d,u=q[i].u;
            q[i].l=n+1-u,q[i].d=l;
            q[i].r=n+1-d,q[i].u=r;
            ask[q[i].l].pb({q[i].d , i});
            //cout << q[i].l << ' ' << q[i].r << ' ' << q[i].d << " " << q[i].u << endl;
        }
        fen.ini(n);
        rep(i,1,n+1){
            for(auto e : ask[i]) q[e.se].ans += c2(fen.sum(e.fi - 1));
            fen.add(a[i] , 1);
        }
    }
    rep(i,0,Q) printf("%lld\n",q[i].ans);
    return 0;
}