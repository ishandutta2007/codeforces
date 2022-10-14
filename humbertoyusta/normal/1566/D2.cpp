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

int block(int x,int block_size){
    return ( x - 1 ) / block_size;
}

int solve(vector<int> c,int block_size){

        int m = (int)c.size() - 1;

        vector<int> d(m+1);
        for(int i=1; i<=m; i++){
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
            //reverse(p[i].begin(),p[i].end());
            int l = lst + 1;
            int r = l + p[i].size() - 1;
            int id = l;
            int curr = 0;
            while( id <= r ){
                while( id + 1 <= r && block(id+1,block_size) == block(id,block_size) ) id ++;

                while( id - 1 >= l && block(id-1,block_size) == block(id,block_size) ){
                    a[id] = p[i] [curr++];
                    id --;
                }
                a[id] = p[i] [curr++];

                while( block(id+1,block_size) == block(id,block_size) ) id ++;
                id ++;
            }
            lst += ( r - l + 1 );
        }

        int inv = 0;
        for(int i=1; i<=m; i++){
            for(int j=i-1; j>=1; j--){
                if( block(i,block_size) != block(j,block_size) ) break;
                inv += ( a[j] < a[i] );
            }
        }

        return inv;
}

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

        vector<int> a(n*m+1);
        for(int i=1; i<=n*m; i++)
            cin >> a[i];

        cout << solve(a,m) << '\n';
    }

    return 0;
}