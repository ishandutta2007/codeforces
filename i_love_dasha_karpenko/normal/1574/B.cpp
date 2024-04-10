#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    int mi = max(0,2*max({a,b,c})-(a+b+c)-1),mx = (a-1)+(b-1)+(c-1);
    if (mi<=m && m<=mx)
        cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}