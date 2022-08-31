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
const int N = 100005;
char s[N], t[N];
int main(){
	scanf("%s", t + 1);
	int m = strlen(t + 1);
	int na = 0;
	int pos = 0;
	for(int i = 1; i <= m; i++){
		na += t[i] == 'a';
		if(i + i - na == m){
			// trace(i);
			bool ok = 1;
			int lft = 1, rgt = i + 1;

			for(; rgt <= m; rgt++){
				if(t[rgt] == 'a'){
					ok = 0;
					break;
				}
				while(t[lft] == 'a') lft++;
				if(t[lft] != t[rgt]) ok = 0;
				lft++;
			}
			if(!ok) printf(":(\n");
			else{
				for(int j = 1; j <= i; j++) s[j] = t[j];
				printf("%s", ((string)(s + 1)).c_str());
			}
			return 0;
		}
	}
	printf(":(\n");
}