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

const int N = 1e6 + 10;
int n , x , y , a[N] , tot;
int pri[N] , _p , vis[N];
ll sum[N];

int main(){
    rep(i,2,N){
        if(!vis[i]) pri[_p++] = i;
        for(int j=0,o;j<_p&&(o=pri[j]*i)<N;++j){
            vis[o] = true;
            if(i % pri[j] == 0)
                break;
        }
    }
    scanf("%d%d%d",&n,&x,&y);
    ll ans = 1ll<<62;
    tot = 1;
    rep(i,0,n) {
        int t;scanf("%d",&t);
        a[tot++] = t;
    }
    sort(a + 1, a + tot);
    rep(i,1,tot) sum[i] = sum[i-1] + a[i];
    rep(i,0,_p){
        int p = pri[i];
        ll s = 0;
        for(int d=1;;++d){
            int right = d * p , left = right - p + 1;
            int mid = right - x / y;
            mid = max(left , mid);
            int sl = lower_bound(a + 1 , a + tot , left) - a;
            int smid = lower_bound(a + 1 , a + tot , mid) - a;
            int sr = upper_bound(a + 1 , a + tot , right) - a - 1;
            if(a[sl] > d * p) continue;
            if(sl < smid){
                s += 1ll * x * (smid - sl);
            }
            if(smid <= sr){
                s += (1ll * (sr - smid + 1) * right - (sum[sr] - sum[smid - 1])) * y;
            }
            if(sr == tot - 1) break;
        }
        ans = min(ans , s);
    }
    printf("%lld\n",ans);
    return 0;
}