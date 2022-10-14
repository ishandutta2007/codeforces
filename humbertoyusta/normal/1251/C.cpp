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

string s;
queue<char> a, b;

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    int tc;
    cin >> tc;
    while( tc-- ){

            cin >> s;

            for( auto i : s )
                if( int( i - '0' ) % 2 == 0 ) a.push(i);
                    else b.push(i);

            while( !b.empty() || !a.empty() ){
                if( b.empty() ){ cout << a.front(); a.pop(); continue; }
                if( a.empty() ){ cout << b.front(); b.pop(); continue; }
                if( a.front() <= b.front() ){ cout << a.front(); a.pop(); continue; }
                cout << b.front(); b.pop(); continue;
            }

            cout << '\n';
    }

    return 0;
}