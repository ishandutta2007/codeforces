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

const int N = 3e5 + 10 , inf = 1<<30;
int a[N] , n , f[31] , g[31];
inline void Update(int &x,int d) {x = max(x , d);}

int main(){
    scanf("%d",&n);
    int s = 0;
    rep(i,1,n+1) scanf("%d",a + i) , a[i] = a[i] / 100 , s += a[i];
    rep(i,0,31) f[i] = -inf;
    f[0] = 0;
    per(x,1,n+1){
        rep(i,0,31) g[i] = -inf;
        rep(i,0,31) if(f[i] != -inf){
            if(a[x] / 10 <= i) Update(g[i - a[x] / 10] , f[i]);
            if(i + a[x] <= 30) Update(g[i + a[x]] , f[i] + a[x]);
        }
        rep(i,0,31) f[i] = g[i];
    }
    int ans = inf;
    rep(i,0,31) if(f[i] != -inf){
        ans = min(ans , s - (s - f[i]) / 10);
    }
    printf("%lld\n",100ll*ans);
    return 0;
}