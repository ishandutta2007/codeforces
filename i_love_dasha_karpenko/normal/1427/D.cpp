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
    ll n;
    cin>>n;

    forn(i,n)cin>>A[i];
    {
        ll flag = 0;
        forn(i,n){
            if (A[i]<A[i-1]){
                flag = 1;
                break;
            }
        }
        if (flag==0){
            cout<<0<<endl;
            return 0;
        }
    }
    vector<vector<ll> > ans;
    ll x = n;
    ll flag = 0;
    while(x>1){
        vector<ll> len;

        if (flag==0){
            ll i = 1;
            while(A[i]>x){
                len.pb(1);
                ++i;
            }
            ll l = 1;
            while(A[i]!=x){
                ++l;
                ++i;
            }
            len.pb(l);
            if (n-len.size()-l+1!=0)
            len.pb(n-len.size()-l+1);

        }
        else{
            reverse(A+1,A+1+n);
            ll i = 1;
            while(A[i]>x){
                len.pb(1);
                ++i;
            }
            ll l = 1;
            while(A[i]!=x){
                ++l;
                ++i;
            }
            len.pb(l);
            if (n-len.size()-l+1!=0)
            len.pb(n-len.size()-l+1);
            reverse(A+1,A+1+n);
            reverse(len.begin(),len.end());
        }

        vector<vector<ll> > V;
        ll ptr = 1;
        for(ll to:len){
            vector<ll> blank;
            V.pb(blank);
            forn(j,to){
                V.back().pb(A[ptr++]);
            }
        }
        reverse(V.begin(),V.end());
        ptr = 1;
        if (len.size()!=1)
        ans.pb(len);
        for(vector<ll> to:V){
            for(ll t:to)A[ptr++] = t;
        }
        flag^=1;
        --x;
    }
    if (A[1]!=1){
        vector<ll> len;
        forn(i,n){
            len.pb(1);
        }
        ans.pb(len);
    }
    cout<<ans.size()<<endl;
    for(vector<ll> to:ans){
        cout<<to.size()<<' ';
        for(ll t:to)cout<<t<<' ';
        cout<<endl;
    }
    return 0;

}