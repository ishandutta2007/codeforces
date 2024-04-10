#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 fgdfgdg
const ll DIM = 2E5+7;
ll B[DIM];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k,m;
        cin>>n>>k>>m;
        for(ll i = 1;i<=m;++i)cin>>B[i];
        ll need = n-m;
        if (need%(k-1)!=0){
            cout<<"NO\n";
            continue;
        }
        while(need-(k-1)>=k-1)need-=k-1;
        //cout<<need<<endl;
        ll flag = 0;
        for(ll i = 1;i<=m;++i){
            ll x;
            x = B[i];
            ll bef = x-i,after = n-x-(m-i);
            if (min(bef,after)*2>=need){
                flag = 1;
            }
        }

        need/=(k-1);
        if (flag==0)cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}