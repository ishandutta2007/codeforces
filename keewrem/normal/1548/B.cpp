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
#define sz(x) (int)b((x).size())
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

ll st[200010][20];
ll query(int l, int r){
	if(l == r)return 0;
	int log = 31-__builtin_clz(r-l);
	//cout << "q l r " << l << " " << r << " log "<<log<<" " << __gcd(st[l][log],st[r-(1<<log)][log]) << endl;
	return __gcd(st[l][log],st[r-(1<<log)][log]);
}

void solve(){
	int N; cin >> N;
	vll v(N);
	for(auto &x: v)cin >> x;
	FOR(i,N)FOR(j,20)st[i][20] = 0;
	FOR(i,N-1)st[i][0] = abs(v[i+1]-v[i]);
	FOR(j,19)FOR(i,N-(1<<(j+1)))st[i][j+1] = __gcd(st[i][j],st[i+(1<<j)][j]);
	ll g = 0,r = 0;
	ll ans = 1;
	for(int i = 1; i < N; i++){
		g = query(r,i);
		while(g == 1)g = query(++r,i);
		ans = max(ans,i-r+1);
	}
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
}