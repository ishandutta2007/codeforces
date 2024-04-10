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

        string s;
        string t;
        cin >> s;

        vector<string> v;

        t = s[0] + s[0];
        v.push_back(t);
        t.clear();

        for(int i=0; i<n-1; i++){
            if( s[i] < s[i+1] ){
                int k = i;
                t.clear();
                for(int j=0; j<=k; j++)
                    t += s[j];
                for(int j=k; j>=0; j--)
                    t += s[j];
                v.push_back(t);

                while( k - 1 >= 0 && s[i] == s[k-1] )
                    k --;
                t.clear();
                for(int j=0; j<=k; j++)
                    t += s[j];
                for(int j=k; j>=0; j--)
                    t += s[j];
                v.push_back(t);
                break;
            }
        }

        t = s[0];
        for(int i=1; i<n; i++){
            if( s[i] < s[i-1] ){
                t += s[i];
                continue;
            }
            if( s[i] < t[0] ){
                t += s[i];
                continue;
            }
            break;
        }
        string p = t;
        reverse(p.begin(),p.end());
        t += p;
        v.push_back(t);

        sort(v.begin(),v.end());
        cout << v[0] << '\n';
    }

    return 0;
}