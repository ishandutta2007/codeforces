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
	string s;
	int n;
	int x, y;
	cin >> n >> x >> y;
	cin >> s;

	int cnt = 0;
	for(int i = 0; i < s.length(); i++){
		while(i < n && s[i] == '1') i++;
		if(i == n) break;
		while(i < n && s[i] == '0') i++;
		cnt++;
	}

	if(cnt == 0){
		cout << 0;
		return 0;
	}
	if(y <= x){
		cout << cnt * (ll) y;
		return 0;
	}
	cout << x * (ll) (cnt - 1) + y;
}