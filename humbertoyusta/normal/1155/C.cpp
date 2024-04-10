/** Name: Humberto Yusta Gomez
    Pais: Cuba
    Prov: Villa Clara
    Grado: 11no
    Copyright              **/
#include<bits/stdc++.h>
#define maxn 1000010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) 31 - __builtin_clz(x)
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,m;
ll a[maxn],b[maxn],gcd;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    if( n == 1 ){
        cout << "YES\n";
        cout << a[1] << ' '  << 1;
        return 0;
    }

    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=m; i++)
        cin >> b[i];

    sort(a+1,a+n+1);

    gcd = a[2] - a[1];
    for(int i=3; i<=n; i++)
        gcd = __gcd( gcd , a[i] - a[i-1] );

    for(int i=1; i<=m; i++){
        if( gcd % b[i] == 0 ){
            cout << "YES\n";
            cout << a[1] << ' ' << i;
    return 0;
        }
    }

    cout << "NO";

    return 0;
}