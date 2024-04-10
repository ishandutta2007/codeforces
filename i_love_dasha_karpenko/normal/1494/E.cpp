//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;
ll in[DIM],out[DIM];
ll gi(char ch){
    return ch-'a'+1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    memset(out,-1,sizeof(out));
    ll r1 = 0,r2 = 0;
    map<pair<ll,ll> , pair<ll,ll> > M;
    for(ll i = 1;i<=m;++i){
        char type;
        cin>>type;
        if (type=='+'){
            ll u,v,c;
            char ch;
            cin>>u>>v>>ch;
            c = gi(ch);
            ll flag = 0;
            if (u>v)
                flag = 1,swap(u,v);
            ll p1 = (M[{u,v}].first!=0 && M[{u,v}].second!=0),p2 = (M[{u,v}].first==M[{u,v}].second && M[{u,v}].first!=0);
            if (flag) M[{u,v}].second = c;
            else M[{u,v}].first = c;
            ll c1 = (M[{u,v}].first!=0 && M[{u,v}].second!=0),c2 = (M[{u,v}].first==M[{u,v}].second && M[{u,v}].first!=0);
            r1+=c1-p1;
            r2+=c2-p2;
        }
        if (type=='-'){
            ll u,v,c;
            cin>>u>>v;
            c = 0;
            ll flag = 0;
            if (u>v)
                flag = 1,swap(u,v);
            ll p1 = (M[{u,v}].first!=0 && M[{u,v}].second!=0),p2 = (M[{u,v}].first==M[{u,v}].second && M[{u,v}].first!=0);
            if (flag) M[{u,v}].second = c;
            else M[{u,v}].first = c;
            ll c1 = (M[{u,v}].first!=0 && M[{u,v}].second!=0),c2 = (M[{u,v}].first==M[{u,v}].second && M[{u,v}].first!=0);
            r1+=c1-p1;
            r2+=c2-p2;
        }
        if (type=='?') {
            ll k;
            cin>>k;
            if (k%2 && r1)cout<<"YES\n";
            else if (r2)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }

    return 0;
}