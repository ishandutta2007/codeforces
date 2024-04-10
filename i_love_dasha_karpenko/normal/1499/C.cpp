//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E5+7;
const ll INF = 1E15;

void solve(){
    ll n;
    cin>>n;

    ll mi[] = {INF,INF},s[] = {n,n},res = INF;
    ll sum = 0;
    for(ll i = 1;i<=n;++i){
        ll x;
        cin>>x;
        mi[i%2] = min(mi[i%2],x);
        s[i%2]--;
        sum+=x;
        if (i>1)
        res = min(res,s[0]*mi[0]+s[1]*mi[1]+sum);
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}