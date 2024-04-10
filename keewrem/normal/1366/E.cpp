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
const ll MOD = 998244353;

void solve(){
    int N,M; cin >> N >>M;
    vi v(N), b(M);
    for(int &i: v)cin >> i;
    for(int &i: b)cin >> i;
    ll ans = 1;
    reverse(all(v));
    int ind = M-1;
    ll c = 0,k = 0,kc = 0;
    for(int i = 0; i < N; i++){
    //    cout << i << " " << v[i] << " " << c << endl;
        if(v[i] < b[ind]){
            if(ind <= 0 || v[i] < b[ind-1]){
                cout << "0\n";
                return;
            }
            ans*=c; ans %= MOD;
            c = 0; k = 0; ind--;
        }
        if(v[i] == b[ind]){
            if(!k)kc++;
            k = 1; c++;
        }
        if(k && v[i] > b[ind]){
            c++;
        }
    }
    if(kc != M)ans = 0;
    cout << ans << endl;
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