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

int n, a[303][303];

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    cin >> n;

    int c = 0;
    for(int i=1; i<=n; i++){
        if( i & 1 )
                for(int j=1; j<=n; j++)
                    a[j][i] = ++c;
            else
                for(int j=n; j>=1; j--)
                    a[j][i] = ++c;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}