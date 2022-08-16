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
const ll INF = 1e16;
int main(){
	string s = "codeforces";
	ll k; cin >> k;
	ll lo = 10, hi = 500;
	while(lo < hi){
		ll mid = (lo + hi) >> 1;
		vector<ll> freq(10);
		for(int i = 0; i < 10; i++) freq[i] = mid / 10;
		for(int i = 0; i < (mid % 10); i++) freq[i]++;
		ll num = 1;
		for(int i = 0; i < 10; i++) num *= freq[i];
		if(num>=k) hi = mid;
		else lo = mid + 1;
	}

	ll mid = lo;
	vector<ll> freq(10);
	for(int i = 0; i < 10; i++) freq[i] = mid / 10;
	for(int i = 0; i < (mid % 10); i++) freq[i]++;
	for(int i = 0; i < 10; i++) for(int j = 0; j < freq[i]; j++) cout << s[i];
	cout << endl;
}