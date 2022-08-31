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

vector<string> vec[26];
int f[26];
int main(){
	string s;
	cin >> s;
	int l = s.length();
	double ans = 0;
	for(int i = 0; i < l; i++){
		vec[s[0] - 'a'].push_back(s);
		rotate(s.begin(), s.begin() + 1, s.end());
	}
	for(int i = 0; i < 26; i++){
		if(vec[i].empty()) continue;
		int mx = 0;
		double mul = vec[i].size() / (double)l;
		for(int j = 0; j < l; j++){
			memset(f, 0, sizeof f);
			for(int k = 0; k < vec[i].size(); k++)
				f[vec[i][k][j] - 'a']++;
			int cnt = 0;
			for(int k = 0; k < 26; k++) if(f[k] == 1){
				cnt++;
			}
			mx = max(mx, cnt);
		}
		ans += mx / (double)l;
	}
	printf("%.10lf\n", ans);
}