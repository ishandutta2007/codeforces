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

ll g(ll a, ll b){
	return (a - 1) / b + 1;
}
int main(){
	ll k, d, t;
	cin >> k >> d >> t;
	d *= g(k, d);

	ll alpha = (2 * t) / (d + k);
	if(alpha * (d + k) == 2*t){
		cout << alpha * d << endl;
		return 0;
	}
	double ans = alpha * d;
	double rem = 1. - alpha * ((d + k) / (2. * t));

	if(k / (double) t >= rem){
		cout << setprecision(15) << fixed << ans + rem * t;
	}
	else{
		rem -= k / (double)t;
		cout << setprecision(15) << fixed << ans + k + rem * (2. * t) << endl;
	}
}