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
    int N,K; cin >> N >> K;
    vi v(N);
    pii c[N][K+1];
    for(int i = 0; i < N; i++)for(int j = 0; j <= K; j++){c[i][j] = {2*N,2*N};}
    for(auto &x: v){
        cin >> x;
        for(int i = 2; i*i <= x; i++){
            if(x%(i*i) == 0)x/=(i*i);
        }
    }
    map<int,int> sesso;
    vi l(N);
    for(int i = 0; i < N; i++){
        l[i] = sesso[v[i]];
        sesso[v[i]] = i+1;
    }
    int ans = 2*N;
    int b = 0;
    pii t;
    for(int j = 0; j <= K; j++){
        c[0][j] = {1,1};
        b = 0;
        for(int i = 1; i < N; i++){
            t = min(make_pair(c[i-1][j].fi,c[i-1][j].se+1),c[i][j]);
            if(l[i] > i-t.se+1){
                c[i][j] = min(make_pair(t.fi+1,1),c[i][j]);
                if(j < K)c[i][j+1] = min(c[i][j+1],make_pair(c[i-1][j].fi,c[i-1][j].se+1));
            }else c[i][j] = t;

        }
    }
    for(int i = 0; i <= K; i++)ans = min(ans,c[N-1][i].fi);
    cout << ans << endl;
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