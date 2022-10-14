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

int query(int a,int b,int c){
    cout << "? " << a << ' ' << b << ' ' << c << '\n';
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
    cin >> tc;
    while( tc-- ){

        int n;
        cin >> n;

        int a, b, c;
        while( true ){
            a = rng(1,n);
            b = rng(1,n);
            c = rng(1,n);
            if( a == b || a == c || b == c )
                continue;
            if( query(a,b,c) <= ( n - 8 ) / 6 )
                break;
        }

        vector<pair<int,int>> v;
        for(int i=1; i<=n; i++)
            if( i != a && i != b )
                v.push_back({query(a,b,i),i});
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        int id1 = v[0].s;

        if( v[0].first == v[1].first )
            swap( v[1] , v[3] );

        int o1 = query(id1, v[1].s, a);
        int o2 = query(id1, v[2].s, a);

        if( v[1].first == v[2].first && o2 < o1 )
            swap( v[1] , v[2] );

        int id2 = v[1].s;

        vector<int> ans(n+1);
        ans[id1] = 1;
        ans[id2] = 2;

        for(int i=1; i<=n; i++)
            if( !ans[i] )
                ans[i] = query(id1,id2,i) + 2;

        if( ans[1] > ans[2] ){
            for(int i=1; i<=n; i++)
                ans[i] = n - ans[i] + 1;
        }

        cout << "! ";
        for(int i=1; i<=n; i++)
            cout << ans[i] << " \n"[i==n];
        cout.flush();
        int ok;
        cin >> ok;
        assert( ok == 1 );
    }


    return 0;
}