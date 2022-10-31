#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 3E5+7;
const ll INF = 1E18;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll bot = k-(n-k);
        for(ll i = 1;i<bot;++i)cout<<i<<' ';
        for(ll i = k;i>=bot;--i)cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}