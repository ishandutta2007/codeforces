//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 1E3+7;
ll A[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll cnt = 0;
        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            A[i] = ch-'0';
            if (A[i]==0)
                ++cnt;
        }
        if (n%2 && A[n/2+1]==0 && cnt>1){
            cout<<"ALICE\n";
        }
        else cout<<"BOB\n";
    }
    return 0;
}