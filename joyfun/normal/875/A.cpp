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

int n;

int main(){
    cin >> n;
    vi ans;
    for(int i=0;i<=200&&i<=n;++i) {
        int t = n - i , s = 0 , x = t;
        while(x) s += x % 10 , x /= 10;
        if(t + s == n) ans.pb(t);
    }
    reverse(all(ans));
    cout << sz(ans) << endl;
    rep(i,0,sz(ans)) cout << ans[i] << " \n"[i+1==sz(ans)];
    return 0;
}