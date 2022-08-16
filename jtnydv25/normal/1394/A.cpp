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

int main(){
	int n, d, m; sd(n); sd(d); sd(m);
	vector<int> a(n);
	vector<ll> b, c;
	for(int i = 0; i < n; i++){
		sd(a[i]);
		if(a[i] > m) b.push_back(a[i]);
		else c.push_back(a[i]);
	}

	sort(all(b), greater<int>());
	sort(all(c), greater<int>());
	for(int i = 1; i < sz(b); i++) b[i] += b[i - 1];
	for(int i = 1; i < sz(c); i++) c[i] += c[i - 1];
	ll ans = c.empty() ? 0 : c.back();
	for(int k = 1; k <= sz(b); k++){
		ll sm = b[k - 1];
		ll num = min((ll)sz(c), n - k - (k - 1) * (ll) d);
		if(num >= 0){
			ans = max(ans, sm + (num == 0 ? 0 : c[num - 1]));
		}
	}
	printf("%lld\n", ans);
}