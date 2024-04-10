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
        ll n,x,y;
        cin>>n>>x>>y;

        ll d = y-x;
        ll an = d;
        forn(j,d){
            if (d%j==0 && d/j+1<=n)an = min(an,j);
        }
        ll by = y;
        ll flag = 0;
        forn(i,n){

            cout<<y<<' ';
            if (flag==0){
                y-=an;
                if (y<=0){
                    flag = 1;
                    y = by+an;
                }
            }
            else y+=an;

        }

        cout<<endl;

    }
    return 0;
}