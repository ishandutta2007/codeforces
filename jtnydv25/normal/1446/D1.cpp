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
const int N = 200005;
int pref[N];
int mx[2 * N];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	vector<int> freq(n + 1);
	vector<int> perm(n + 1);
	iota(all(perm), 0);
	for(int & x : a) cin >> x, freq[x]++;
	sort(all(perm), [&](int x, int y){return freq[x] > freq[y];});
	if(freq[perm[0]] == freq[perm[1]]){
		cout << n << endl;
		return 0;
	}
	int x = perm[0];
	int ans = 0;
	for(int y = 1; y <= 100; y++) if(y != x){
		memset(mx, -1, sizeof mx);
		pref[0] = N;
		for(int i = 1; i <= n; i++){
			pref[i] = pref[i - 1];
			if(a[i - 1] == x) pref[i]++;
			else if(a[i - 1] == y) pref[i]--;
		}
		for(int i = n; i >= 1; i--){
			if(mx[pref[i]] == -1) mx[pref[i]] = i;
			int R = mx[pref[i - 1]];
			if(R != -1) ans = max(ans, R - i + 1);
		}
	}
	cout << ans << endl;
}