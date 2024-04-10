#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

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
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 2E5+7;

const ll MOD = 1e9+7;

const ll INF = 1E19+70;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
struct node{
    ll fi,sc,type;
};
const ll LOG = 40;
ll basis[LOG+1];
set<ll> S;
vector<node> ans;
ll add(ll x){
    if (x>=po(LOG+1))return 0;
    ll flag = 0;
    for(ll i = LOG;i>=0;--i){
        if (basis[i]==0 && (x&po(i))){
            basis[i] = x;
            flag = 1;
            break;
        }
        else if (basis[i]!=0 && (x&po(i))){
            if (S.count(x^basis[i])==0)
            ans.pb({x,basis[i],1});
            x^=basis[i];

        }
    }
    return flag;

}

ll makenum(ll x){
    ll cur = 0;
    for(ll i = LOG;i>=0;--i){
        if (x&po(i)){
            if (cur!=0 && S.count(basis[i]^cur)==0){
                ans.pb({basis[i],cur,1});
            }
            cur^=basis[i];
            S.insert(cur);
        }
    }
    return cur;

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // cout<<((57174604644393ll)^(4398046511144ll))<<endl;
    ll x;
    cin>>x;

    add(x);
    ll sz = 1;
    while(basis[0]==0){
        ll u = 0,v = 0;
        for(ll i = 0;i<=LOG;++i){
            if (basis[i]==0)continue;
            u += getInt(0,1)*po(i);
            v += getInt(0,1)*po(i);

        }

        if (u==0){
            for(ll i = 0;i<=LOG;++i){
                if (basis[i]!=0){
                    u = po(i);
                    break;
                }
            }
        }
        if (v==0){
            for(ll i = 0;i<=LOG;++i){
                if (basis[i]!=0){
                    v = po(i);
                    break;
                }
            }
        }
         u = makenum(u);
        v = makenum(v);
        if (S.count(u+v)==0){
            S.insert(u+v);
            ans.pb({u,v,0});
        }
        if (add(u+v)){


            ++sz;
        }
    }

    cout<<ans.size()<<endl;
    for(node to:ans)cout<<to.fi<<' '<<(to.type==0?'+':'^')<<' '<<to.sc<<endl;
    return 0;

}