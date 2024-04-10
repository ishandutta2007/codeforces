//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 1E5+7;
ll simp(ll x){
    ll sq = sqrt(x);
    for(ll i = 2;i<=sq;++i)if (x%i==0)return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll d;
        cin>>d;
        ll a = d+1;
        while(!simp(a))++a;
        ll b = a+d;
        while(!simp(b))++b;
        cout<<a*b<<endl;
    }

    return 0;
}