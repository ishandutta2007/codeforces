#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define ps push
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) int((x).size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < (k); i++)
#define foll(i,k) for(long long i = 0; i < (k); i++)
#define FORr(i,k) for(int i = (k)-1; i >= 0; i--)
#define folr(i,k) for(long long i = (k)-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD =   1000000007;//   998244353;

void solve(){
    ll N,K;
    cin >> N >> K;
    ll nx[N][34], s[N][34], m[N][34];
    for(int i = 0; i < N;i++){
        cin >> nx[i][0]; 
    }
    for(int i = 0; i < N; i++){cin >> s[i][0]; m[i][0] = s[i][0];}
    for(int j = 0; j < 33; j++){
        FOR(i,N){
            nx[i][j+1] = nx[nx[i][j]][j];
            m[i][j+1] = min(m[i][j],m[nx[i][j]][j]);
            s[i][j+1] = s[i][j] + s[nx[i][j]][j];
        }
    }
    ll n,mn,ss;
    vi v;
    for(int i = 0; i < 34; i++)if(K&((1LL)<<i))v.pb(i);
    FOR(i,N){
        n = i; ss = 0; mn = 1e9;
        for(auto x: v){
            mn = min(mn,m[n][x]);
            ss += s[n][x];
            n = nx[n][x];
        }
        cout << ss << " " << mn << "\n";
    }
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
    return 0;
}