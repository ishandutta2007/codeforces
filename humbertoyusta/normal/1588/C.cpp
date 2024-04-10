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

///0-min
///1-max
template<typename T>
struct RMQ{
    vector<vector<T>> rmq;
    vector<int> lg;
    int n;
    bool t;
    RMQ(vector<T> &v,bool t) : n(v.size()),t(t)
    {
        lg.push_back(-1);
        for(int i=1;i<=n+5;i++)
            lg.push_back(lg.back()+!(i&(i-1)));

        for(int i=0;i<=n;i++)
            rmq.push_back(vector<T>(lg[n]+1));
        for(int i=0;i<n;i++)
            rmq[i][0]=v[i];
        for(int j=1;j<=lg[n];j++)
            for(int i=0;i+(1<<j)<=n;i++)
            {
                if(!t)
                    rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
                else
                    rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
            }
    }

    T query(int l,int r)
    {
        if(l>r)
            swap(l,r);
        int po=lg[r-l+1];
        if(!t)
            return min(rmq[l][po],rmq[r-(1<<po)+1][po]);
        return max(rmq[l][po],rmq[r-(1<<po)+1][po]);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;

        ll ans = 0;
        vector<ll> a(n+1), f(n+1), odd(n+1), even(n+1);
        for(int i=1; i<=n; i++){
            cin >> a[i];
            f[i] = a[i] - f[i-1];
            if( i & 1 ){
                odd[i] = f[i];
                even[i] = INF;
            }
            else{
                even[i] = f[i];
                odd[i] = INF;
            }
            ans += ( a[i] == 0 );
        }

        vector<pair<ll,int>> eventseven[n+2], eventsodd[n+2];
        RMQ rmqodd(odd,0);
        RMQ rmqeven(even,0);
        for(int i=1; i<=n; i++){
            int idodd = i;
            int ideven = i;
            if( ( i & 1 ) == 1 ){
                for(int j=20; j>=0; j--){
                    if( idodd + (1<<j) <= n ){
                        if( rmqodd.query(i,idodd+(1<<j)) >= -f[i-1] )
                            idodd += (1<<j);
                    }
                }
                for(int j=20; j>=0; j--){
                    if( ideven + (1<<j) <= n ){
                        if( rmqeven.query(i,ideven+(1<<j)) >= f[i-1] )
                            ideven += (1<<j);
                    }
                }
            }
            else{
                for(int j=20; j>=0; j--){
                    if( idodd + (1<<j) <= n ){
                        if( rmqodd.query(i,idodd+(1<<j)) >= f[i-1] )
                            idodd += (1<<j);
                    }
                }
                for(int j=20; j>=0; j--){
                    if( ideven + (1<<j) <= n ){
                        if( rmqeven.query(i,ideven+(1<<j)) >= -f[i-1] )
                            ideven += (1<<j);
                    }
                }
            }
            int id = min( idodd , ideven );
            if( ( i & 1 ) == 1 ){
                eventsodd[i+1].push_back({-f[i-1],1});
                eventsodd[id+1].push_back({-f[i-1],-1});
                eventseven[i+1].push_back({f[i-1],1});
                eventseven[id+1].push_back({f[i-1],-1});
            }
            else{
                eventsodd[i+1].push_back({f[i-1],1});
                eventsodd[id+1].push_back({f[i-1],-1});
                eventseven[i+1].push_back({-f[i-1],1});
                eventseven[id+1].push_back({-f[i-1],-1});
            }
        }

        map<ll,int> mpodd, mpeven;
        for(int i=0; i<=n; i++){
            for( auto j : eventsodd[i] )
                mpodd[j.f] += j.s;
            for( auto j : eventseven[i] )
                mpeven[j.f] += j.s;
            if( i & 1 )
                ans += mpodd[f[i]];
            else
                ans += mpeven[f[i]];
        }
        cout << ans << '\n';
    }

    return 0;
}