#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x1 dfds
#define y1 dsfdsfe
#define endl '\n'
const ll DIM = 107;
ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
        }

        for(ll i = 2;i<=n;i+=2){
            cout<<A[i]<<' '<<-A[i-1]<<' ';
        }
        cout<<endl;

    }
    return 0;

}