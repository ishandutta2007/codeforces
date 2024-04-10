#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    ll a[3];
    for(int c = 0;c<3;c+=1){
        cin>>a[c];
    }
    // x mod y = a => x = k1*y + a
    // y mod z = b => y = k2*z + b
    // z mod x = c => z = k3*x + c
    for(int lo = 0;lo<3;lo+=1){

        ll ans[3];
        ans[lo] = a[lo];
        ans[(lo+2)%3] = a[(lo+2)%3] + ans[lo];
        ll g = ((a[(lo+1)%3]-ans[(lo+2)%3])/a[lo]) + (((a[(lo+1)%3]-ans[(lo+2)%3])/a[lo])!=0);
        ans[(lo+2)%3] += g*a[lo];
        ans[(lo+1)%3] = ans[(lo+2)%3] + a[(lo+1)%3];
        bool flag = 1;
        for(int j = 0;j<3;j+=1){
            if (ans[(j+1)%3]==0 || ans[j]%ans[(j+1)%3]!=a[j]){
                flag = 0;
                break;
            }
        }
        if (flag){
            cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<endl;
            return;
        }
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