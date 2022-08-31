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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), b(n), c(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		for(int i = 0; i < n; i++) cin >> c[i];
		vector<int> p(n);
		p[0] = a[0];
		for(int i = 1; i < n - 1; i++){
			if(a[i] != p[i - 1]) p[i] = a[i];
			else p[i] = b[i];
		}
		p[n - 1] = a[n - 1];
		if(p[n - 2] != b[n - 1] && p[0] != b[n - 1]) p[n - 1] = b[n - 1];
		if(p[n - 2] != c[n - 1] && p[0] != c[n - 1]) p[n - 1] = c[n - 1];
		for(int i = 0; i < n; i++) cout << p[i] << " "; cout << endl;
		
	}
}