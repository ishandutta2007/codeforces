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

int n, m, a[maxn], b[maxn], n1, n2;
bool mk[maxn];
vector<int> g[maxn];

int main(){
    ios_base::sync_with_stdio(0);  cin.tie(0);
    cout.setf(ios::fixed);  cout.precision(0);

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if( g[i].size() < n - 1 ){
            n1 = i;
            for( auto j : g[i] )
                mk[j] = 1;
            break;
        }
    }

    for(int i=1; i<=n; i++)
        if( !mk[i] && i != n1 ){
            n2 = i;
            break;
        }

    if( n1 == 0 || n2 == 0 ){
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    int cont = 3;
    for(int i=1; i<=n; i++){
        if( i == n1 ){ a[i] = 1; continue; }
        if( i == n2 ){ a[i] = 2; continue; }
        a[i] = cont++;
    }

    for(int i=1; i<=n; i++){
        cout << a[i];
        if( i < n ) cout << ' ';
            else cout << '\n';
    }

    cont = 3;
    for(int i=1; i<=n; i++){
        if( i == n2 ) cout << 1;
            else cout << a[i];
        if( i < n ) cout << ' ';
            else cout << '\n';
    }

    return 0;
}