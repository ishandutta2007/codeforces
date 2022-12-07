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

const int N = 1e3 + 10;
int a[N][5] , n;

int main(){
    scanf("%d",&n);
    rep(i,0,n) rep(j,0,5) scanf("%d",a[i] + j);
    if(n <= 100){
        vi ans;
        rep(i,0,n){
            bool ok = true;
            rep(j,0,n) rep(k,j+1,n) if(j != i && k != i){
                int x = 0;
                rep(t,0,5) x += (a[j][t] - a[i][t]) * (a[k][t] - a[i][t]);
                ok &= x <= 0;
            }
            if(ok) ans.pb(i+1);
        }
        printf("%d\n",sz(ans));
        rep(i,0,sz(ans)) printf("%d\n",ans[i]);
    } else {
        puts("0");
    }
    return 0;
}