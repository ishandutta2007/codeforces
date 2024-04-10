#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_popcount(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int u = ( i / 2 ) * ( n * 2 ) + ( i % 2 ) * 2;
        for(int j=0; j<n/2; j++){
            cout << u << ' ' << u + 1;
            u += 4;
            if( j + 1 < n / 2 ) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}