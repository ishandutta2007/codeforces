#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;
const ll MOD = 1e9+7;
const ll M1 = 1e9+7;
const ll INF = 1E17;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

struct node{
    ll fi,sc,th;
};
bool mc(node a,node b){

    return a.fi<b.fi;
}
node B[DIM];
const ll MAXN = 1E6;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    ll n,m;
    cin>>n>>m;
    ll cnt = 0;
    vector<node > V;
    super_set S1;
    ll res = 1;
    forn(i,n){
        ll y,l,r;
        cin>>y>>l>>r;
        if (l==0 && r==MAXN){
            S1.insert({y,i});
            ++res;
            continue;
        }
        V.pb({l,r,y});
    }
    sort(V.begin(),V.end(),mc);
    forn(i,m){
        ll x,l,r;
        cin>>x>>l>>r;
        B[i] = {x,l,r};
    }
    sort(B+1,B+1+m,mc);
    ll ptr = 0;

    super_set S;
    priority_queue<pp,vector<pp>,greater<pp> > Q;
    forn(i,m){
        while(ptr<V.size() && V[ptr].fi<=B[i].fi){
            Q.push({V[ptr].sc,ptr});
            S.insert({V[ptr].th,ptr});
            ++ptr;
        }
        while(!Q.empty() && Q.top().fi<B[i].fi){
            pp t = Q.top();
            Q.pop();
            //cout<<S.size()<<' ';
            S.erase({V[t.sc].th,t.sc});
           // cout<<S.size()<<endl;
            //cout<<V[t.sc].th<<' '<<t.sc<<endl;
        }
        ll v1 = S.order_of_key({B[i].th+1,-INF});
        ll r = v1-S.order_of_key({B[i].sc,-INF});
        if (B[i].sc==0 && B[i].th==MAXN)r++;

        res+=r;
        //cout<<r<<endl;
        res+= (S1.order_of_key({B[i].th+1,-INF})-S1.order_of_key({B[i].sc,-INF}));

    }
    cout<<res<<endl;


    return 0;
}