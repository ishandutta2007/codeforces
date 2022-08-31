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
const int N = 100005;
int cnt[32];
int a[N];
void add(int x, int z){
	for(int i = 30; i >= 0; i--) cnt[i] += z * (x >> i & 1);
}

int main(){
	int n; sd(n);
	int ans = 0;
	for(int i = 1; i <= n; i++) sd(a[i]), add(a[i], 1);
	int which = -1;
	for(int i = 1; i <= n; i++){
		add(a[i], -1);
		int val = 0;
		for(int j = 30; j >= 0; j--) if(a[i] >> j & 1) if(!cnt[j]) val |= 1 << j;
		if(val >= ans) which = i;
		ans = max(ans, val);
		add(a[i], 1);
	}
	printf("%d ", a[which]);
	for(int i = 1; i <= n; i++) if(i != which) printf("%d ", a[i]); printf("\n");
}