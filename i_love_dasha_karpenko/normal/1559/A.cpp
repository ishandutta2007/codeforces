//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    int total = (1<<30)-1;
    for(int i = 1;i<=n;++i){
        int x;
        cin>>x;
        total&=x;
    }
    cout<<total<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    //t = 1;
    while(t--)
        solve();
    return 0;
}