#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
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
const int N = 100;
ll ax, bx, ay, by, p, q, t;
int main(){
	vector<ll> x(1), y(1);
	cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
	cin >> p >> q>> t;
	for(int i = 1; ; i++){
		ll _x = x.back() * ax + bx;
		ll _y = y.back() * ay + by;
		if(max(_x, _y) > 2.1e16) break;
		x.push_back(_x);
		y.push_back(_y);
	}
	// trace(x);
	// trace(y);
	int n = sz(x);
	vector<ll> best(n);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ll rem = t - (abs(x[i] - p) + abs(y[i] - q));
		if(rem < 0) continue;
		for(int j = 0; j <= i; j++){
			for(int k = j; k < n; k++){
				if(x[i] - x[j] + y[i] - y[j] + x[k] - x[j] + y[k] - y[j] <= rem){
					ans = max(ans, max(k, i) - j + 1ll);
				}
			}
		}
	}
	cout << ans;
}