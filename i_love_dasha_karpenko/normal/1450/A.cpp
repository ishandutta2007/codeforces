#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll cnt = 0;
        string s;
        cin>>s;
        for(char to:s){
            if (to=='b')++cnt;
        }
        for(ll i = 0;i<cnt;++i)cout<<'b';
        for(char to:s){
            if (to!='b')cout<<to;
        }
        cout<<endl;
    }
    return 0;
}