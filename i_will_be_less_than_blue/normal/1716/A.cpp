#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;cin>>n;
    int ans=n/3;
    if (n==0) ans=0;
    else if (n==1) ans=2;
    else if (n==2) ans=1;
    else if (n%3) ans++;
    cout<<ans<<'\n';

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}