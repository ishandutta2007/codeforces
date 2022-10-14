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
const int MAXN = 200010;
vi adj[MAXN];
int s[MAXN],N;
ll mx, ans;
bool vis[MAXN];

void dfs(int n){
    s[n] = 1;
    for(auto x: adj[n]){
        if(s[x] == 0){
            dfs(x); s[n] += s[x];
        }
    }
    ans+=s[n];
}

void dd (int n){
    vis[n] = 1;
    mx =max(mx,ans);
    for(auto x: adj[n]){
        if(vis[x])continue;
        ans+=N-2*s[x];
        dd(x);
    }
    ans += 2*s[n]-N;
}

void solve(){
    cin >> N;
    int a,b;
    FOR(i,N-1){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    dd(1);
    cout << mx << endl;

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