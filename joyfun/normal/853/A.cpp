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

const int N = 3e5 + 10;
int k , n , c[N] , ans[N];
priority_queue<pii> Q;

int main(){
    scanf("%d%d",&n,&k);
    rep(i,1,n+1) scanf("%d",c + i);
    ll cost = 0;
    int j = 1;
    rep(i,k+1,k+n+1){
        while(j <= n && j <= i) Q.push(mp(c[j] , j)) , ++j;
        int t = Q.top().se;Q.pop();
        ans[t] = i;
        cost += 1ll * (i - t) * c[t];
    }
    printf("%lld\n",cost);
    rep(i,1,n+1) printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}