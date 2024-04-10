#include<bits/stdc++.h>
#define maxn 200010
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

int a[200020];

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> a[i];
        bool flag = 1;
        for(int i=1; i<n; i++)
            if( abs( a[i] - a[i+1] ) >= 2 ){
                cout << "YES\n";
                cout << i << ' ' << i + 1 << '\n';
                flag = 0;
                break;
            }
        if( flag ) cout << "NO\n";
    }

    return 0;
}