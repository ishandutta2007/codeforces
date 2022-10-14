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
    int N,M; cin >> N >> M;
    vi v[N];
    vector<array<int,3>> m;
    FOR(i,N){
        v[i].resize(M);
        FOR(j,M)cin >> v[i][j];
        FOR(j,M)m.pb({v[i][j],i,j});

    }
    sort(all(m));
    int ind = 0;
    vi pres(M,0);
    FOR(i,M)pres[m[i][2]] = 1;
    vi ms;
    FOR(i,M)if(!pres[i])ms.pb(i);
    FOR(i,M)pres[i] = 0;
    FOR(i,M){
        if(pres[m[i][2]] == 1)swap(v[m[i][1]][m[i][2]],v[m[i][1]][ms[ind++]]);
        else pres[m[i][2]]++;
    }
    FOR(i,N){
        FOR(j,M)cout << v[i][j] << " ";
        cout << endl;
    }
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