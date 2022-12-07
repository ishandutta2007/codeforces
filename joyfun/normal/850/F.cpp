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

const int P = 1e9 + 7;
int inv(int x){
    return x == 1 ? x : P - ll(P/x)*inv(P%x)%P;
}
const int N = 1e5 + 10;
int n , s , Mx , a[N] , p[N];

int main(){
    cin >> n;
    rep(i,0,n) cin >> a[i] , s += a[i] , Mx = max(Mx , a[i]);
    p[1] = 1ll * (s - 1) * (s - 1) % P * inv(s) % P;
    rep(i,1,Mx) p[i + 1] = ((p[i] * 2ll - p[i - 1] - 1ll * (s - 1) * inv(s - i) % P) % P + P)%P;
    int ans=0;
    rep(i,0,n) (ans+=p[a[i]])%=P;
    cout << ans << endl;
    return 0;
}