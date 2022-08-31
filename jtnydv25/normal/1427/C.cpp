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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int r, n;
	cin >> r >> n;
	vector<int> x(n + 1, 1), y(n + 1, 1), t(n + 1);
	for(int i = 1; i <= n; i++) cin >> t[i] >> x[i] >> y[i];
	vector<int> dp(n + 1), mx(n + 2);

	for(int i = n; i >= 0; i--){
		int v = 0;
		int j = i + 1;
		for(; j <= i + 1000 && j <= n; j++){
			if(abs(x[j] - x[i]) + abs(y[j] - y[i]) <= t[j] - t[i]) v = max(v, dp[j]);
		}
		v = max(v, mx[j]);
		dp[i] = v + 1;
		mx[i] = max(mx[i + 1], dp[i]);
	}
	cout << dp[0] - 1 << "\n";
}