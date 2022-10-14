#include<bits/stdc++.h>
#define inf 1000000007
#define f first
#define s second
#define maxn 100010
using namespace std;
typedef pair<int,int> ii;

int a[maxn], b[maxn], l(1000000007), r, cnt;
set<int> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){

    int n; cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }

    s.clear();
    l = 1000000007, r = 0, cnt = 0;
    for(int i=1; i<=n; i++)
        if( a[i] != b[i] ){
            s.insert(b[i]-a[i]);
            l = min( l , i );
            r = max( r , i );
            cnt++;
        }

    if( s.size() == 0 ){ cout << "YES\n"; continue; }
    if( s.size() == 1 && r - ( l - 1 ) == cnt && *s.begin() > 0 ){ cout << "YES\n"; continue; }
    cout << "NO\n";

    }

    return 0;
}