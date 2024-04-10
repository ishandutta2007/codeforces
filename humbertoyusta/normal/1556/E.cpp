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
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here -------------------------------------

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

    int n, q;
    cin >> n >> q;

    vector<ll> c(n+1), a(n+1), b(n+1);
    vector<ll> sum(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    for(int i=1; i<=n; i++){
        c[i] = b[i] - a[i];
        sum[i] = sum[i-1] + c[i];
    }

    RMQ<ll> rmqmin(sum,0);
    RMQ<ll> rmqmax(sum,1);

    for(int i=1; i<=q; i++){
        int l, r;
        cin >> l >> r;
        if( rmqmin.query(l,r) >= sum[l-1] && sum[r] - sum[l-1] == 0 ){
            cout << rmqmax.query(l,r) - sum[l-1] << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }

    return 0;
}