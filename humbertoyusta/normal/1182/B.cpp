#include <bits/stdc++.h>
#define maxn 505
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,m;
bool flag,cnt;
char a[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
            cnt |= ( a[i][j] == '*' );
        }

    if( !cnt ){
        cout << "NO";
        return 0;
    }

    for(int i=2; i<n; i++)
        for(int j=2; j<m; j++){
            if( flag == 1 ) continue;
            if( a[i][j] == '*' && a[i+1][j] == '*' && a[i-1][j] == '*' && a[i][j-1] == '*' && a[i][j+1] == '*' ){

                a[i][j] = '.';

                int w = i+1, h = j;
                while( w <= n && a[w][h] == '*' )
                    a[w][h] = '.', w++;

                w = i-1, h = j;
                while( w >= 1 && a[w][h] == '*' )
                    a[w][h] = '.', w--;

                w = i, h = j+1;
                while( h <= m && a[w][h] == '*' )
                    a[w][h] = '.', h++;

                w = i, h = j-1;
                while( h >= 1 &&  a[w][h] == '*' )
                    a[w][h] = '.', h--;

                flag = 1;
            }
        }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if( a[i][j] == '*' ){
                cout << "NO";
                return 0;
            }

    cout << "YES";

    return 0;
}