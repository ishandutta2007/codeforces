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

int main(){
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.length(); i++){
		for(int l = 1; l <= s.length() - i; l++){
			string t = s.substr(i, l);
			string t2 = t;
			reverse(t.begin(), t.end());
			if(t2 != t) ans = max(ans, l);
		}
	}
	cout << ans;
}