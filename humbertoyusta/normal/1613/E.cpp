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
const int mod2 = 1000000007;
const int mod = 998244353;
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

int n, m;

int encode(int i,int j){
    return i * ( m + 2 ) + j;
}

pair<int,int> decode(int x){
    return { x / ( m + 2 ) , x % ( m + 2 ) };
}

int mx[4] = { 1 , -1 , 0 , 0 };
int my[4] = { 0 , 0 , -1 , 1 };

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){
        cin >> n >> m;

        vector<string> a(n+2);

        for(int i=0; i<=m+1; i++)
            a[0] += '#';
        for(int i=1; i<=n; i++){
            cin >> a[i];
            a[i] = '#' + a[i] + '#';
        }
        for(int i=0; i<=m+1; i++)
            a[n+1] += '#';

        pair<int,int> st;
        vector<int> lft((n+3)*(m+3));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if( a[i][j] != '#' ){
                    lft[encode(i,j)] += ( a[i-1][j] != '#' );
                    lft[encode(i,j)] += ( a[i+1][j] != '#' );
                    lft[encode(i,j)] += ( a[i][j+1] != '#' );
                    lft[encode(i,j)] += ( a[i][j-1] != '#' );
                }
                if( a[i][j] == 'L' ){
                    st = { i , j };
                }
            }
        }

        vector<int> mk((n+3)*(m+3));
        queue<int> q;
        q.push(encode(st.f,st.s));
        while( !q.empty() ){
            pair<int,int> u = decode(q.front());
            q.pop();
            for(int i=0; i<4; i++){
                if( a[u.f+mx[i]][u.s+my[i]] == '.' ){
                    int v = encode(u.f+mx[i],u.s+my[i]);
                    lft[v] --;
                    if( lft[v] <= 1 && !mk[v] ){
                        mk[v] = 1;
                        q.push(v);
                    }
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if( a[i][j] == '.' && mk[encode(i,j)] )
                    cout << '+';
                else
                    cout << a[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}