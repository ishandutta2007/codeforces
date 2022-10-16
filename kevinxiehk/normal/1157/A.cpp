#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ans=9;
    while(n>9){
        ans++;
        n++;
        while(n%10==0)n/=10;
    }
    cout<<ans<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    //cin>>t;
    t=1;

    while(t--)solve();
    return 0;
}