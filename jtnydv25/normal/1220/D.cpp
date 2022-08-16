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
ll b[N];
int num[64];

inline int zeroes(ll x){
	for(int i = 0; i < 64; i++) if(x >> i & 1) return i;
}

int main(){
	int n; sd(n);
	for(int i = 0; i < n; i++){
		scanf("%lld", b + i);
		num[zeroes(b[i])] ++;
	}
	int mx = 0, bits = 0;
	for(int j = 0; j < 64; j++) if(num[j] > mx){
		mx = num[j];
		bits = j;
	}
	vector<ll> removals;
	for(int i = 0; i < n; i++) if(zeroes(b[i]) != bits) removals.push_back(b[i]);
	printf("%d\n", sz(removals));
	for(auto it : removals) printf("%lld ", it);
}