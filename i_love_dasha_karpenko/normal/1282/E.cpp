#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 1E5+7;
const ll INF = 1e19;
map<pp,set<ll> > M;
struct node{
    ll a,b,c;
};
const bool operator<(const node &a,const node &b){
    if (a.a==b.a){
        if (a.b==b.b)return a.c<b.c;
        return a.b<b.b;
    }
    return a.a<b.a;
}
map<node,ll> mm;
set<pp> S[DIM];
set<ll> del;
vector<ll> ans;
vector<ll> ans1;

void dfs(ll a,ll b,ll c){
    {
        pp p = {min(a,b),max(a,b)};
        ll f = 0;
        while(!M[p].empty()){
            if (del.count(*M[p].begin())==0){
                f = *M[p].begin();
            }
            M[p].erase(*M[p].begin());
            if (f!=0)break;
        }
        del.insert(f);
        if (f!=0)dfs(a,f,b);
       else if (ans.empty() || ans.back()!=a)ans.pb(a);
    }
    {
        pp p = {min(c,b),max(c,b)};
        ll f = 0;
        while(!M[p].empty()){
            if (del.count(*M[p].begin())==0){
                f = *M[p].begin();
            }
            M[p].erase(*M[p].begin());
            if (f!=0)break;
        }
        del.insert(f);
        if (f!=0){
            dfs(b,f,c);
        }
        else if (ans.empty() || ans.back()!=b)ans.pb(b);}

    {
        pp p = {min(a,c),max(a,c)};
        ll f = 0;
        while(!M[p].empty()){
            if (del.count(*M[p].begin())==0){
                f = *M[p].begin();
            }
            M[p].erase(*M[p].begin());
            if (f!=0)break;
        }
        del.insert(f);
        if (f!=0)dfs(c,f,a);
        else if (ans.empty() || ans.back()!=c)ans.pb(c);
    }
    vector<ll> V = {a,b,c};
    sort(V.begin(),V.end());
    ans1.pb(mm[{V[0],V[1],V[2]}]);
    //ans.pb(b);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n-2){
            ll A[3];
            cin>>A[0]>>A[1]>>A[2];
            sort(A,A+3);
            ll a=  A[0];
            ll b = A[1];
            ll c = A[2];
            M[{a,b}].insert(c);
            M[{a,c}].insert(b);
            M[{b,c}].insert(a);
            mm[{a,b,c}] = i;
            S[a].insert({b,c});
            S[b].insert({a,c});
            S[c].insert({a,b});
        }
        pp ff = *S[1].begin();
        //ans.pb(1);
        del.insert(1);
        del.insert(ff.fi);
        del.insert(ff.sc);
        dfs(1,ff.fi,ff.sc);
        //ans.pb(ff.sc);
        if (ans.back()==1)ans.pop_back();
        for(ll to:ans)cout<<to<<' ';
        cout<<endl;
        for(ll to:ans1)cout<<to<<' ';
        cout<<endl;
        forn(i,n)S[i].clear();
        M.clear();
        del.clear();
        ans.clear();
        ans1.clear();
        mm.clear();
    }
    return 0;
}