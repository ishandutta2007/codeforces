#include <bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,t,k,a[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> t;
    while( t-- ){

        cin >> n >> k;

        for(int i=1; i<=n; i++)
            cin >> a[i];

        sort(a+1,a+n+1);

        int ans = inf+inf, p = -1;
        for(int i=1; i<=n-k; i++){
            if( ans > ( a[i+k] - a[i] + 1 ) / 2 ){
                ans = ( a[i+k] - a[i] + 1 ) / 2;
                p = ( a[i] + a[i+k] ) / 2;
            }
        }

        cout << p << '\n';
    }

    return 0;
}