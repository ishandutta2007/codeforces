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

const int N = 1000006;
ll c1[N], c2[N];

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	ll n, r1, r2, r3, d;
	cin >> n >> r1 >> r2 >> r3 >> d;
	vector<ll> a(n + 1);
	vector<ll> dp(n + 1);
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ll x = min(a[i] * r1 + 2 * r1, r2 + r1); 
		c2[i] = c2[i - 1] + x;
		c1[i] = min(x + 2 * d, r3 + a[i] * r1);
	}
	
	ll mn = 1LL << 60;
	for(int i = 1; i <= n; i++){
		int j = i - 2;
		if(j >= 0) mn = min(mn, dp[j] - c2[j] - 3 * d * j + d * (j != 0));
		dp[i] = min(c1[i] + dp[i - 1] + d * (i != 1), mn + 3 * d * (i - 1) + c2[i]);
	}
	ll ans = dp[n];
	for(int i = 1; i < n; i++){
		ans = min(ans, dp[i - 1] + c2[n - 1] - c2[i - 1] + d * (2 * n - 2 * i + (i!=1)) + c1[n]);
	}
	cout << ans << endl;
}