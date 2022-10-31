#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 3E4+7;

const ll NUM = 2050;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if (n%NUM){
            cout<<"-1\n";
            continue;
        }
        ll res = 0;

        while(n>0){
            ll x = NUM;
            while(x*10<=n)x*=10;
            res++;
            n-=x;
        }
        cout<<res<<endl;
    }

    return 0;
}