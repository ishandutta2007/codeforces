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

template<class T,class U>
ostream& operator<<(ostream& os,const map<T, U> & mp){
	os << "{";
	int i = 0;
	for(auto it : mp){
		if(i) os<<", ";
		os << it;
		i++;
	}
	os << "}";	
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
int a[N], fst[N], lst[N], perm[N];
int main(){
	int n, q; sd(n); sd(q);
	for(int i = 1; i <= n; i++) sd(a[i]), lst[a[i]] = i;
	for(int i = n; i >= 1; i--) fst[a[i]] = i;
	vector<pii> vec;
	for(int i = 1; i < N; i++) if(fst[i]) vec.push_back({fst[i], lst[i]});
	sort(all(vec));
	int l = 0, r = -1, ans = 0;

	for(auto it : vec){
		int L = it.F, R = it.S;
		// trace(l, r, L, R);
		if(L > r){
			if(l <= r){
				map<int, int> freq;
				for(int j = l; j <= r; j++) freq[a[j]]++;
				int mx = 0;
				for(auto it2 : freq) mx = max(mx, it2.S);
				// trace(l, r, mx);
				ans += r - l + 1 - mx;
			}
			l = L, r = R;
		} else{
			r = max(r, R);
		}
	}
	if(l <= r){
		map<int, int> freq;
		for(int j = l; j <= r; j++) freq[a[j]]++;
		int mx = 0;
		for(auto it2 : freq) mx = max(mx, it2.S);
		// trace(l, r, mx);
		ans += r - l + 1 - mx;
	}
	printf("%d\n", ans);
}