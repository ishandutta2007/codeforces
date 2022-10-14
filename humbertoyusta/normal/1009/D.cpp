#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> ans;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=2; i<=n; i++)
        ans.push_back({1,i});
    m -= n - 1;
    if( m < 0 ){ cout << "Impossible\n"; return 0; }

    for(int i=2; i<=min(n,1000); i++)
        for(int j=i+1; j<=min(n,1000); j++)
            if( __gcd(i,j) == 1 && m ){
                ans.push_back({i,j});
                m--;
            }

    if( m != 0 ){ cout << "Impossible\n"; return 0; }
    cout << "Possible\n";
    for( auto i : ans )
        cout << i.first << ' ' << i.second << '\n';

    return 0;
}