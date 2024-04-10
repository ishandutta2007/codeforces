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

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin);

    int tc;
    cin >> tc;
    while( tc-- ){
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort( a , a + 3 );
        if( a[2] <= a[0] + a[1] + 1 ) cout << "Yes\n";
            else cout << "No\n";
    }

    return 0;
}