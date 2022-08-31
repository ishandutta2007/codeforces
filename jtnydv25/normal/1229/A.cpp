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
const int N = 7005;
int removed[N];
ll a[N];
int	b[N];
int deg[N];

void out(int x, int n){
	removed[x] = 1;
	for(int i = 1; i <= n; i++) if(!removed[i] && ((a[i] & a[x]) != a[i])) deg[i]--;
}

int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", b + i);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) if(i != j && ((a[i] & a[j]) != a[i])) deg[i]++;
	}

	int curr = n;
	while(curr){
		int orig = curr;
		for(int i = 1; i <= n; i++) if(!removed[i] && deg[i] == curr - 1){
			out(i, n);
			curr--;
			break;
		}
		if(orig == curr) break;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) if(!removed[i]) ans += b[i];
	printf("%lld\n", ans);
}