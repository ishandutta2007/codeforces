#include<bits/stdc++.h>
#define maxn 1510
#define inf 1000000007
#define  f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
#define int long long
using namespace std;
typedef long double ld;
typedef pair<int,int> ii;

string a[maxn];
map<int,int> mp;
int ans = 0;

int32_t main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    //freopen("a.in","r",stdin

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++){
        int h=0;
        for(int j=0; j<m; j++){
            if(a[i][j]=='S') h = h * 3ll + 0ll * (a[i][j]=='S');
            if(a[i][j]=='E') h = h * 3ll + 1ll * (a[i][j]=='E');
            if(a[i][j]=='T') h = h * 3ll + 2ll * (a[i][j]=='T');
        }
        mp[h]++;
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int nxt = 0;
            for(int k=0; k<m; k++){
                if( a[i][k] == 'S' && a[j][k] == 'S' ){
                    nxt = nxt * 3 + 0;
                    continue;
                }
                if( a[i][k] == 'E' && a[j][k] == 'E' ){
                    nxt = nxt * 3 + 1;
                    continue;
                }
                if( a[i][k] == 'T' && a[j][k] == 'T' ){
                    nxt = nxt * 3 + 2;
                    continue;
                }
                if( ( a[i][k] == 'E' && a[j][k] == 'T' ) || ( a[i][k] == 'T' && a[j][k] == 'E' ) ){
                    nxt = nxt * 3 + 0;
                    continue;
                }
                if( ( a[i][k] == 'S' && a[j][k] == 'T' ) || ( a[i][k] == 'T' && a[j][k] == 'S' ) ){
                    nxt = nxt * 3 + 1;
                    continue;
                }
                if( ( a[i][k] == 'S' && a[j][k] == 'E' ) || ( a[i][k] == 'E' && a[j][k] == 'S' ) ){
                    nxt = nxt * 3 + 2;
                    continue;
                }
            }
            ans += mp[nxt];
        }
    }

    cout << ans / 3 << '\n';

    return 0;
}