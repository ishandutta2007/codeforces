#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; //    
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 200007;
const ll INF = 10000000007;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
struct node{
    ll fi,sc,pos;
};
bool const operator<(node &a,node &b){
    if (a.fi==b.fi)return a.sc<b.sc;
    return a.fi<b.fi;
}
ll n;
typedef tree<pp, null_type, less<pp>, rb_tree_tag, tree_order_statistics_node_update> ms;
ms S,S1;

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;

    forn(i,n){

        ll x,y; cin>>x>>y;
        if (x>y)swap(x,y);
        ll pos = S1.order_of_key({x,-20});
        auto t = S1.find_by_order(pos);
        if (t==S1.end()){
            S1.insert({y,x});
            S.insert({x,y});
            cout<<S.size()<<" ";
            continue;
        }
        pp el = *t;
        pos = S.order_of_key({el.sc,el.fi});
        auto it = S.find_by_order(pos);
        pp res = {x,y};
        vector<pp> er;
        while (it!=S.end()){
            pp a = *it;
            if (a.fi>y)break;
            res.sc = max(res.sc,a.sc);
            res.fi = min(res.fi,a.fi);
            er.pb(a);
            it++;
        }
        for(pp to:er){S.erase(to);S1.erase({to.sc,to.fi});}
        S.insert(res);
        S1.insert({res.sc,res.fi});
        cout<<S.size()<<' ';

    }
    cout<<endl;
    return 0;
}