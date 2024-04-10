#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 2*10E4 +7;
const ll INF = 10E17;

string s;
ll T[DIM*4][30];
ll gi(char ch){
    return ch-'a'+1;
}
ll unite(ll t){
    forn(i,29){
        T[t][i] = T[t*2+1][i]+T[t*2+2][i];
    }
}
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t][gi(s[tl])]++;
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    unite(t);
}
ll query(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (l>tr || tl>r)return 0;
    if (l<=tl && tr<=r)return T[t][val];
    ll tm = (tl+tr)/2;
    return query(t*2+1,tl,tm,l,r,val)+query(t*2+2,tm+1,tr,l,r,val);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    ll n = s.length()-1;
    buildtree(0,0,n);
    ll q;
    cin>>q;
    forn(qe,q){
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        if (l==r){
            cout<<"Yes\n";
            continue;
        }
        ll cnt = 0;
        forn(i,29){
            ll q = query(0,0,n,l,r,i);
            cnt+=(q!=0);
        }
        if (cnt==2 && s[l]!=s[r])cout<<"Yes\n";
        else if ((cnt==2 && s[l]==s[r]) || cnt==1)cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}