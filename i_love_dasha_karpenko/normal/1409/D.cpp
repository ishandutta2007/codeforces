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

const ll DIM = 5000+7;
const ll INF = 1E19;
const ll MAXN = 1E6;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,s;
        cin>>n>>s;
        vector<ll> num;
        while(n>0){
            num.pb(n%10);
            n/=10;
        }
        reverse(num.begin(),num.end());
        ll ptr = 0;
        ll sum = 1;
        ll su = 0;
        for(ll to:num)su+=to;
        for(ll to:num){
            ++ptr;
            sum+=to;
            if (sum>s)break;
        }
        if (su<=s){
            cout<<0<<endl;
            continue;
        }
        ll mult = 1;
        ll ss = 0;
        for(ll i = num.size()-1;i>=ptr-1;--i){

            ss+=num[i]*mult;
            mult*=10;
        }
        cout<<mult-ss<<endl;

    }
    return 0;
}