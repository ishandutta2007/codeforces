/// Code by humbertoyusta
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
const int maxn = 1010;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
int qpow(int b,int e){
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



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){

        int n, m;
        cin >> n >> m;

        vector<int> c(m+1), d(m+1);
        for(int i=1; i<=m; i++){
            cin >> c[i];
            d[i] = c[i];
        }
        sort(d.begin(),d.end());

        int cnt = 0;
        map<int,int> mp;

        for(int i=1; i<=m; i++){
            if( d[i] != d[i-1] )
                mp[d[i]] = ++ cnt;
        }

        vector<int> p[m+1];
        for(int i=1; i<=m; i++){
            p[mp[c[i]]].push_back(i);
        }

        int lst = 0;
        vector<int> a(m+1);
        for(int i=1; i<=m; i++){
            reverse(p[i].begin(),p[i].end());
            for( auto i : p[i] ){
                lst ++;
                a[i] = lst;
            }
        }

        int inv = 0;
        for(int i=1; i<=m; i++)
            for(int j=1; j<i; j++){
                inv += ( a[j] < a[i] );
            }

        cout << inv << '\n';
    }

    return 0;
}