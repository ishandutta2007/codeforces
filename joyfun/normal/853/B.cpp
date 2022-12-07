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

const int N = 1e5 + 10;
int n,m,K;
struct ele{
    int d,t,c;
    bool operator < (const ele&b) const{
        return d < b.d;
    }
};
const ll inf = 1ll<<60;
vector<ele> lft , rgt;
vector<ll> costlft , costrgt;

void solve(vector<ele>&a,vector<ll>&cost){
    sort(all(a));
    cost = vector<ll>(sz(a) , inf);
    map<int,int> Mp;
    ll ans = 0;
    rep(i,0,sz(a)){
        if(!Mp.count(a[i].t)) Mp[a[i].t] = a[i].c , ans += a[i].c;
        else if(a[i].c < Mp[a[i].t]) ans += a[i].c - Mp[a[i].t] , Mp[a[i].t] = a[i].c;
        if(sz(Mp) == n) cost[i] = ans;
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&K);
    rep(i,0,m){
        int d,f,t,c;
        scanf("%d%d%d%d",&d,&f,&t,&c);
        if(f == 0) rgt.pb(ele{-d,t,c});
        else lft.pb(ele{d,f,c});
    }
    solve(lft , costlft);
    solve(rgt , costrgt);
    ll ans = inf;
    int j = 0;ll Minright = inf;
    per(i,0,sz(lft)){
        while(j < sz(rgt) && (-rgt[j].d - lft[i].d - 1) >= K) Minright = min(Minright , costrgt[j]) , ++j;
        ans = min(ans , costlft[i] + Minright);
    }
    if(ans == inf) puts("-1");
    else printf("%lld\n",ans);
    return 0;
}