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
const int maxn = 200010;
const int maxk = 1510;
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

int x[maxn], y[maxn], add[maxn], t[maxn], a[maxk][maxk];
int curr, c_ans;

void update(int id,int val){
    if( id >= maxn ) return;
    add[id] += val;
    if( curr > id )
        c_ans += val;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, m;
    cin >> n >> m;

    const int K = sqrt(n);

    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }

    vector<int> modj(K+1);
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        curr = i;

        if( x[v] + y[v] > K ){
            if( u == 1 ){
                for(int j=i; j<=m; j+=x[v]+y[v]){
                    update(j+x[v],1);
                    update(j+x[v]+y[v],-1);
                }
                t[v] = i;
            }
            else{
                for(int j=t[v]; j<=m; j+=x[v]+y[v]){
                    update(j+x[v],-1);
                    update(j+x[v]+y[v],1);
                }
            }
        }
        else{
            if( u == 1 ){
                t[v] = i;
                int st = (t[v]+x[v])%(x[v]+y[v]);
                int ed = (t[v]+x[v]+y[v]-1)%(x[v]+y[v]);//db(st)db(ed)
                for(int j=st; ; j++){
                    if( j >= x[v]+y[v] )
                        j -= x[v]+y[v];
                    a[j][x[v]+y[v]] ++;
                    if( j == ed ) break;
                }
            }
            else{
                int st = (t[v]+x[v])%(x[v]+y[v]);
                int ed = (t[v]+x[v]+y[v]-1)%(x[v]+y[v]);//db(st)db(ed)
                for(int j=st; ; j++){
                    if( j >= x[v]+y[v] )
                        j -= x[v]+y[v];
                    a[j][x[v]+y[v]] --;
                    if( j == ed ) break;
                }
            }
        }

        c_ans += add[i];
        int ans = c_ans;
        for(int j=1; j<=K; j++){
//            modj[j] = modj[j] + 1;
//            if( modj[j] >= j )
//                modj[j] -= j;
//            ans += a[modj[j]][j];
        ans += a[i%j][j];
        }
        cout << ans << '\n';
    }

    return 0;
}