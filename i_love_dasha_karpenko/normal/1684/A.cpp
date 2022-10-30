#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    if (n<10){
        cout<<n<<endl;
    }
    else if (n<100){
        cout<<n%10<<endl;
    }
    else{
        int ans = 10;
        while(n){
            ans = min(ans,n%10);
            n/=10;
        }
        cout<<ans<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}