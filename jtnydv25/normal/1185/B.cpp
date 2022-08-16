#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())


#ifdef LOCAL
#define cerr cout
#else
#endif

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

const int N = 1000006;
char s[N], t[N];

int main(){
	int T; sd(T);
	while(T--){
		scanf("%s", s);
		scanf("%s", t);
		int n = strlen(s), m = strlen(t);
		if(n > m){
			printf("NO\n");
			continue;
		}
		int j = 0;
		bool ok = 1;
		for(int i = 0; i < n; i++){
			if(j == m || s[i] != t[j]){
				ok = 0;
				break;
			}
			if(i != n - 1 && s[i] == s[i + 1]){
				j++;
			} else{
				while(j < m && s[i] == t[j]) j++;
			}
		}
		ok &= (j == m);
		printf(ok ? "YES\n" : "NO\n");
	}
}