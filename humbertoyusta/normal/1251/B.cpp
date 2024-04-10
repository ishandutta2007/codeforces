#include<bits/stdc++.h>
#define maxn 100010
#define mod 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int q, n;
string a;

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    int tc;
    cin >> tc;
    while( tc-- ){

        int sp = 0, si = 0, c0 = 0, c1 = 0;

        cin >> n;

        for(int i=1; i<=n; i++){
            cin >> a;
            //db(a)
            if( a.size() % 2 == 1 ) si = si + 1;
                else sp = sp + 1;
            for( auto j : a ){
                if( j == '0' ) c0 = ( c0 + 1 ) % 2;
                    else c1 = ( c1 + 1 ) % 2;
            }
            //db(c0)db(c1)
        }

        if( si == 0 ){ cout << max( 0 , n - max( c1 , c0 ) ) << '\n'; continue; }
        if( si % 2 == 1 ){ cout << n - 1 + ( c0 + c1 == 1 ) << '\n'; continue; }
        cout << n << '\n'; continue;
    }

    return 0;
}