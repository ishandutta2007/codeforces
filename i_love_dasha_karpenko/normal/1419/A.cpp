//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll f1 = 0,f2 = 0;

        for(ll i = 0;i<s.length();++i){
            if (i%2==0 && (s[i]-'0')%2)f1 = 1;
            if (i%2 && (s[i]-'0')%2==0)f2 = 1;
        }
        if (n%2==0 && f2)cout<<2<<endl;
        else if (n%2==0)cout<<1<<endl;
        else if (n%2 && f1)cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}