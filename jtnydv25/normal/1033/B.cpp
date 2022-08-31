#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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

bool is_prime(ll n){
	for(ll x = 2; x * x <= n; x++) if(n % x == 0) return 0;
	return 1;
}
string f(ll a, ll b){
	if(a - b >= 2) return "NO";
	return is_prime(a + b) ? "YES":"NO";
}

int main(){
	ll a, b, t;
	cin>>t;
	while(t--){
		cin >> a >> b;
		cout << f(a, b)<<endl;
	}
}