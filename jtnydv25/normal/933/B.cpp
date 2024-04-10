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
vector<int> vec;
int main(){
	int k;
	ll p;
	cin >> p >> k;
	while(p != 0){
		int t = (p % k + k) % k;
		vec.push_back(t);
		p -= t;
		p /= (-k);
	}
	printf("%d\n", (int)vec.size());
	for(int i = 0; i < vec.size(); i++) printf("%d ", vec[i]);
}