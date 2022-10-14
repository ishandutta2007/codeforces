#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const int mod2 = 998244353;
const ll INF = 1ll * mod * mod;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    ll pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

int query(int id){
    cout << "? " << id << '\n';
    cout.flush();
    int ret;
    cin >> ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    //tc = 1;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;

        vector<int> mk(n+1), p(n+1);
        for(int i=1; i<=n; i++){
            if( !mk[i] ){
                deque<int> v;
                while( true ){
                    int x = query(i);
                    if( mk[x] )
                        break;
                    v.push_back(x);
                    mk[x] = 1;
                }
                while( v.front() != i ){
                    v.push_back(v.front());
                    v.pop_front();
                }
                for(int i=0; i<v.size(); i++){
                    p[v[i]] = v[(i+1)%v.size()];
                }
            }
        }

        cout << "! ";
        for(int i=1; i<=n; i++){
            cout << p[i];
            if( i < n ) cout << ' ';
                else cout << '\n';
        }
        cout.flush();
    }

    return 0;
}