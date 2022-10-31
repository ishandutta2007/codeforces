#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll MAXN = 1E10;
ll sqr(ll x){
    ll l = 0,r = sqrt(x);
    while(l!=r){
        ll tm = (l+r+1)/2;
        if (tm*tm*tm>x)r = tm-1;
        else l = tm;
    }
    return l;
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        ll sq = sqr(x);
        ll flag = 0;
        for(ll i = 1;i<=sq;++i){
            ll ss = sqr(x-i*i*i);
            if (ss*ss*ss==x-i*i*i && i*i*i!=x){
                cout<<"YES\n";
                flag = 1;
                break;
            }
        }
        if (flag==0)
        cout<<"NO\n";
    }
    return 0;
}