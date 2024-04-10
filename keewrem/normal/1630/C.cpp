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
const int MAXN = 3000010;

void solve(){

	int N; cin >> N;
	vi v(N); for(auto &x: v)cin >> x;
	vi last(N+1,0);
	for(int i = 0;i < N; i++)last[v[i]] = i;
	int mx = 0, st = 0;
	while(st < N && last[v[st]] <= st+1)st++;
	vector<pii> s;
	int ans = 0;
	for(int i=st; i < N; i++){
		if(last[v[i]] <= i+1)continue;
		if(s.empty()){
			s.push_back({i,last[v[i]]});
		}else if(last[v[i]]>s.back().second){
			while(!s.empty() && s.back().first > i)s.pop_back();
			s.push_back({max(s.back().second,i),last[v[i]]});
		}
	}
//	for(auto x: s)cout << x.fi << " " <<x.se <<endl;
	for(auto x: s)ans += x.se-x.fi-1;
	cout << ans << endl;
	return;
}

int main(){
	int T = 1;
	// cin >> T;
	while(T--)solve();
	return 0;
}