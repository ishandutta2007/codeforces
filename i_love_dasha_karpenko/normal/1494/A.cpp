//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
string s;
ll Check(ll a,ll b,ll c){
    stack<ll> S;
    for(char to:s){
        char sy;
        ll need;
        if (to=='A')need = a;
        if (to=='B')need = b;
        if (to=='C')need = c;
        if (need==1)
            if (S.empty() || S.top()==1)S.push(1);
            else S.pop();
        else
            S.push(0);
    }
    return S.empty();
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        cin>>s;
        ll flag = 0;
        for(ll i = 0;i<2;++i)
            for(ll j = 0;j<2;++j)
                for(ll k = 0;k<2;++k)
                    if (Check(i,j,k))
                        flag = 1;
        if (flag==0)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }



    return 0;
}