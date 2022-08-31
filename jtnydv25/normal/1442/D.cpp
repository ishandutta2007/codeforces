#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N = 3005;
const ll INF = 1LL << 60;
ll pref[N][N];
ll sm[N];
int t[N];
ll ans = 0;
int n, k;

void process(vector<ll> & dp, int i){
	for(int j = k; j >= t[i]; j--) dp[j] = max(dp[j], dp[j - t[i]] + sm[i]);
}

void go(vector<ll> & V, int L, int R){
	int mid = (L + R) / 2;
	if(L == R){
		for(int j = 0; j <= t[L] && j <= k; j++){
			ans = max(ans, pref[L][j] + V[k - j]);
		}
		return;
	}
	vector<ll> store = V;
	for(int i = L; i <= mid; i++) process(V, i);
	go(V, mid + 1, R);
	V = store;
	for(int i = mid + 1; i <= R; i++) process(V, i);
	go(V, L, mid);
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		for(int j = 1; j <= t[i]; j++){
			int x; cin >> x;
			if(j < N){
				pref[i][j] = x + pref[i][j - 1];
			}
		}
		t[i] = min(t[i], k);
		sm[i] = pref[i][t[i]];
	}
	vector<ll> dp(k + 1, -INF);
	dp[0] = 0;
	go(dp, 1, n);
	cout << ans << endl;
}