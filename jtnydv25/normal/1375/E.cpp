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
const int N = 1005;
int a[N], pos[N];
ll b[N];
int main(){
	int n; sd(n);
	set<ll> st;
	map<ll, int> compress;
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		b[i] = a[i] * (ll) (1 << 20) + i;
		st.insert(b[i]);
	}
	
	int cnt = 0;
	for(auto it : st) compress[it] = ++cnt;
	for(int i = 1; i <= n; i++) pos[compress[b[i]]] = i;

	vector<pii> ans;
	int i;
	while(true){
		for(i = 1; i < n; i++) if(pos[i] > pos[i + 1]){
			ans.push_back({pos[i + 1], pos[i]});
			swap(pos[i], pos[i + 1]);
			break;
		}

		if(i == n) break;
	}
	printf("%d\n", sz(ans));
	for(auto it : ans) printf("%d %d\n", it.F, it.S);
}