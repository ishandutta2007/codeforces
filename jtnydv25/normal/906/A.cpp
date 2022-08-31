#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d", &(x))
#define ll long long
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>

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

set<char> valid;
const int N = 100005;
char type[N];
string s[N];
int msk[N];
int mask = 0;
int total = (1 << 26) - 1;
int main(){
	for(int i = 0; i < 26; i++) mask |= (1 << i);
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n; 
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> type[i] >> s[i];
		for(int j = 0; j < s[i].length(); j++)
			msk[i] |= (1 << (s[i][j] - 'a'));
	}
	int ans = s[n][0] - 'a';
	for(int i = 1; i <= n; i++){
		if(i == n){
			cout << 0;
			return 0;
		}
		if(type[i] == '.'){
			mask &= (~msk[i]);
		}
		else if(type[i] == '!'){
			mask &= msk[i];
		}
		else{
			mask &= (~msk[i]);
		}
		if(__builtin_popcount(mask) == 1){
			int cnt = 0;
			for(int j = i + 1; j < n; j++) if(type[j] != '.') cnt++;
			printf("%d\n", cnt);
			return 0;
		}
	}
}