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
    int N; cin >> N;
    vi v(N); for(int &i: v)cin >> i;
    int ans[N][N];
    FOR(i,N)ans[i][i] = v[i];
    vi vv;
    FOR(i,N){
        bool b = 0;
        FOR(j,N-i){
            if(v[j] == i+1){b = 1; continue;}
            vv.pb(v[j]);
            if(b){
                ans[i+j][j-1] = v[j];
            }else ans[i+j+1][j] = v[j];
        }
        v = vv; vv.clear();
    }
    FOR(i,N)FOR(j,i+1){cout << ans[i][j] << " \n"[j==i];}
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