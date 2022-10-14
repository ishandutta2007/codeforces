#include<bits/stdc++.h>
#define maxn 1010
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

    //freopen("a.in","r",stdin

    int tc;
    cin >> tc;
    while( tc-- ){
        int n, last = 10000000;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0, ans = 0;
        for( int i=0; i<s.size(); i++){
            if( s[i] == 'A' ) last = i;
                else ans = max( ans , i - last );
        }
        cout << ans << '\n';
    }

    return 0;
}