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

const ll INF = 1E18+70;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
const ll base = 26;

ll T[DIM];
void add(ll pos,ll delta){
    for(ll i = pos;i<DIM;i+=(i&-i))T[i]+=delta;
}
ll sum(ll pos){
    ll ret = 0;
    for(ll i = pos;i>0;i-=(i&-i))ret+=T[i];
    return ret;
}
ll A[DIM];
queue<ll> Q[base+1];
ll gi(char ch){
    return ch-'a'+1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n){
        char ch;
        cin>>ch;
        A[i] = gi(ch);
        Q[A[i]].push(i);
    }
    reverse(A+1,A+1+n);
    ll res = 0;
    for(ll i = 1;i<=n;++i){
        while(!Q[A[i]].empty()){
            ll pos = Q[A[i]].front();
            Q[A[i]].pop();
            ll bp = pos;
            pos+=sum(pos);
            if (pos<i)continue;
            res+=pos-i;
            add(1,1);
            add(bp+1,-1);
            break;
        }
    }
    cout<<res<<endl;
    return 0;

}