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
	cin.tie(0);
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	if(m < n - 1){
		cout << "NO";
		return 0; 	
	}
	int pos = -1;
	if(s == t){
		cout << "YES"; return 0;
	}
	for(int i = 0; i < n; i++) if(s[i] == '*') pos = i;
	int rem = n - 1 - pos;
	if(pos == -1) cout << "NO";
	else cout << ((s.substr(0, pos) == t.substr(0, pos) && s.substr(pos + 1, n - pos - 1) == t.substr(m - rem, rem))?"YES":"NO");
}