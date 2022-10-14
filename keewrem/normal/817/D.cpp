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
const int MAXN = 1000010;
ll v[MAXN];
ll st[MAXN][21];
int N;
int q(int l, int r){
    int k = 31-__builtin_clz(r-l);
    if(v[st[l][k]] > v[st[r-(1<<k)][k]])return st[l][k];
    else return st[r-(1<<k)][k];
}

ll kek(int l, int r){
    ll k;
    if(r == l+1)k = v[l];
    else if(r < l+1)k = 0;
    else{
        int p = q(l,r);
        k = (ll)v[p]*(p+1-l)*(r-p) + kek(p+1,r) + kek(l,p);
    }
    //cout << l << " " << r << " " << k <<endl;
    return k;
}

void solve(){
    cin >> N;
    FOR(i,N)cin >> v[i];
    FOR(i,N)st[i][0] = i;
    FOR(j,20)FOR(i,N){
        if(i + (1<<j) >= N)st[i][j+1] = st[i][j];
        else if(v[st[i][j]] > v[st[i+(1<<j)][j]])st[i][j+1] = st[i][j];
        else st[i][j+1] = st[i+(1<<j)][j];
    }
    ll ans = kek(0,N);
    FOR(i,N)v[i] *= -1;
    FOR(j,20)FOR(i,N){
        if(i + (1<<j) >= N)st[i][j+1] = st[i][j];
        else if(v[st[i][j]] > v[st[i+(1<<j)][j]])st[i][j+1] = st[i][j];
        else st[i][j+1] = st[i+(1<<j)][j];
    }
    cout << ans + kek(0,N);
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