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

ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll cnt = 0;
        ll left = 0;
        forn(i,n){
            char ch;
            cin>>ch;
            A[i] = 0;
            if (ch=='W'){
                A[i] = 1;
                ++cnt;
            }
            else{
                ++left;
            }
        }
        queue<ll> Q;
        ll last = 1;
        if (cnt==0){
            ll res = (k>0);
            forn(i,k-1)res+=2;
            cout<<res<<endl;
            continue;
        }

        ll res = 0;
        forn(i,n){
            if (A[i]==1){
                Q.push(i);
                ++res;
                if (A[i-1]==1)++res;
            }
        }
        ll cur = Q.front();
        Q.pop();
        vector<ll> V;
        while(!Q.empty()){
            if (Q.front()!=cur+1)
            V.pb(Q.front()-cur-1);
            cur = Q.front();
            Q.pop();
        }
        sort(V.begin(),V.end());


        for(ll to:V){
            if (k<to)break;
            res+=to*2+1;
            k-=to;
            left-=to;
        }
        res+=min(left,k)*2;
        cout<<res<<endl;

    }

    return 0;

}