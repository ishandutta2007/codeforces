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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) int(x.size())
template<typename T>
using pq = priority_queue<T>;
#define FOR(i,k) for(int i = 0; i < k; i++)
#define foll(i,k) for(long long i = 0; i < k; i++)
#define FORr(i,k) for(int i = k-1; i >= 0; i--)
#define folr(i,k) for(long long i = k-1; i >= 0; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


void solve(){
    int N; cin >>N;
    vi t(N); vll s(N);
    vll dp(N,0);
    for(int &x: t){cin >> x; x--;}
    for(ll &x: s)cin >> x;
    ll m,k;
    for(int i = 0; i < N; i++){
        m = 0, k = 0;
        for(int j = i-1; j >= 0; j--){
            k = max(k,m);
            if(t[j] != t[i]){
                m = max(dp[j]+abs(s[j]-s[i]),m);
                dp[j] = max(dp[j],k+abs(s[j]-s[i]));
            }
        }
        dp[i] = m;
    }
    m = 0;
    for(auto x: dp){m = max(x,m);}
    cout << m << endl;
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(NULL);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}