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
// Problem starts here



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    // tc = 1;
    while( tc-- ){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> a[i][j];

        vector<vector<pair<int,int>>> prf(n,vector<pair<int,int>>(m));
        for(int i=0; i<n; i++)
            prf[i][0] = { a[i][0] , a[i][0] };
        for(int i=0; i<n; i++)
            for(int j=1; j<m; j++)
                prf[i][j] = { min( a[i][j] , prf[i][j-1].f ) , max( a[i][j] , prf[i][j-1].s ) };

        vector<vector<pair<int,int>>> suf(n,vector<pair<int,int>>(m));
        for(int i=0; i<n; i++)
            suf[i][m-1] = { a[i][m-1] , a[i][m-1] };
        for(int i=0; i<n; i++)
            for(int j=m-2; j>=0; j--)
                suf[i][j] = { min( a[i][j] , suf[i][j+1].f ) , max( a[i][j] , suf[i][j+1].s ) };


        vector<pair<int,int>> order;
        for(int i=0; i<n; i++)
            order.push_back({a[i][0],i});
        sort(order.begin(),order.end());

        pair<int,int> ans = { -1 , -1 };
        for(int k=0; k<m-1; k++){
            set<pair<int,int>> mn_prf, mx_prf, mn_suf, mx_suf;
            for(int i=0; i<n; i++){
                mn_prf.insert({prf[i][k].f,i});
                mx_suf.insert({suf[i][k+1].s,i});
            }
            for(int i=0; i<n-1; i++){
                int id = order[i].s;
                mn_prf.erase({prf[id][k].f,id});
                mx_suf.erase({suf[id][k+1].s,id});

                mx_prf.insert({prf[id][k].s,id});
                mn_suf.insert({suf[id][k+1].f,id});

                if( (*mn_prf.begin()).f > (*mx_prf.rbegin()).f )
                    if( (*mx_suf.rbegin()).f < (*mn_suf.begin()).f )
                        ans = { k , i };
            }
        }

        if( ans.f == -1 ){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            string s(n,'R');
            for(int i=0; i<=ans.s; i++)
                s[order[i].s] = 'B';
            cout << s << ' ' << ans.f + 1 << '\n';
        }
    }

    return 0;
}