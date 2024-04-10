#include<bits/stdc++.h>
#define inf 1000000007
#define maxn 100010
#define ii pair<int,int>
#define f first
#define s second
using namespace std;
typedef long long ll;

int tc, n;
map<char,int> mp;
string a, b;
map<int,char> ans;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;

    while(tc--){
        int u, v, w;
        cin >> n;
        cin >> u >> v >> w;
        mp['R'] = u;
        mp['P'] = v;
        mp['S'] = w;
        cin >> a;
        b.clear(); ans.clear();
        int cnt = 0, res = 0;
        for( auto i : a ){
            if( i == 'R' && mp['P'] > 0 ){ ans[cnt] = 'P'; mp['P']--; res++; }
            if( i == 'P' && mp['S'] > 0 ){ ans[cnt] = 'S'; mp['S']--; res++; }
            if( i == 'S' && mp['R'] > 0 ){ ans[cnt] = 'R'; mp['R']--; res++; }
            cnt++;
        }
        if( res < ( n + 1 ) / 2 ){ cout << "NO\n"; continue; }
        cout << "YES\n";
        for(int i=0; i<n; i++){
            if( ans[i] ){ cout << ans[i]; continue; }
            if( mp['R'] > 0 ){ cout << 'R'; mp['R']--; continue; }
            if( mp['P'] > 0 ){ cout << 'P'; mp['P']--; continue; }
            if( mp['S'] > 0 ){ cout << 'S'; mp['S']--; continue; }
        }
        cout << '\n';
    }

    return 0;
}