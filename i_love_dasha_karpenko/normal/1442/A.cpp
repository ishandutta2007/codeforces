#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 3E5+7;
ll A[DIM],can[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll pos = 1;
        ll flag = 0;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
        }

        ll mi = A[1];
        for(ll i = 1;i<=n;++i){
            mi = min(A[i],mi);
            mi = min(max(0ll,A[i]-A[i-1]),mi);
            A[i]-=mi;
        }
        flag = 0;
        for(ll i = 1;i<=n;++i){
            if (A[i]<A[i-1]){
                flag = 1;
                break;
            }
        }

        if (flag==1)cout<<"NO\n";
        else cout<<"YES\n";
    }





    return 0;

}