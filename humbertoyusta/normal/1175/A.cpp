#include <bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int t;
ll a, b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> t;
    while( t-- ){
        cin >> a >> b;
        ll res = 0;
        while( a > 0 ){
            res += a % b;
            if( a < b ) break;
            a /= b;
            res++;
        }
        cout << res << '\n';
    }

    return 0;
}