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

const int N = 120;
char s[N][N];
int main(){
	int n, m; sd(n); sd(m);
	int x1 = 1e9, y1 = 1e9, x2 = 0, y2 = 0;
	for(int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; j++) if(s[i][j] == 'B'){
			if(make_pair(i, j) < make_pair(x1, y1)){
				x1 = i;y1 = j;
			}
			if(make_pair(i, j) > make_pair(x2, y2)){
				x2 = i; y2 = j;
			}
		}
	}
	printf("%d %d\n", (x1 + x2) / 2, (y1 + y2) / 2);
}