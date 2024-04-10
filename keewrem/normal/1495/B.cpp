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
    int N; cin >> N;
    vi v(N);
    for(auto &x: v)cin >> x;
    vi p(N,0), n(N,0);
    int m = 0;
    for(int i = 1; i < N; i++){
        if(v[i] > v[i-1])p[i] = p[i-1]+1;
        m = max(m,p[i]);
    }
    for(int i = N-2; i >= 0; i--){
        if(v[i] > v[i+1])n[i] = n[i+1]+1;
        m = max(m,n[i]);
    }
    int mc = 0;
    FOR(i,N){
        if(p[i] == m)mc++;
        if(n[i] == m)mc++;
    }
    int ans = 0;
    if(mc == 2){
        FOR(i,N)if(m%2 == 0 && p[i] == m && n[i] == m)ans++;
    }
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