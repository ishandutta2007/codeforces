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
const int MAXN = 3000010;

void solve(){
	int N;
	cin >> N;
	vi v(N);
	vi cnt(N,0);
	for(auto &x: v){cin >> x; cnt[--x]++;}
	bool p = 1;
	for(int i = 0; i < N; i++){
		if(v[i] != v[N-1-i])p = 0;
	}
	if(p){
		cout << "YES\n";
		return;
	}
	vi rm;
	for(int i = 0; i < N; i++){
		if(v[i] != v[N-i-1]){
			rm.pb(v[i]);
			rm.pb(v[N-i-1]);
			break;
		}
	}
	for(auto x: rm){
		vi k;
		bool p = 1;
		for(auto i: v)if(i != x)k.pb(i);
		for(int i = 0; i < k.size(); i++){
			if(k[i] != k[k.size()-1-i])p = 0;
		}
		if(p){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;
}

int main(){
	int T = 1;
	cin >> T;
	while(T--)solve();
	return 0;
}