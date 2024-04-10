#include <bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define f first
#define s second
#define lg2(x) ( 31 - __builtin_clz(x) )
#define db(x) cerr << #x << ": " << (x) << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n,mn(inf),ans(inf);
map<int,vector<int> > mp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        int u;
        cin >> u;
        mn = min( mn , u );
        mp[u].push_back(i);
    }

    sort( mp[mn] .begin() , mp[mn].end() );

    for(int i=0; i<mp[mn].size()-1; i++)
        ans = min( ans , mp[mn][i+1] - mp[mn][i] );

    cout << ans << '\n';

    return 0;
}