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

const int N = 55;
char s[N][N];

int sx, sy, ex, ey;

int n, m;
bool valid(int i, int j){
	return i >= 0 && i < n && j >= 0 && j < m && s[i][j] != '#';
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char action[105];
int main(){
	sd(n); sd(m);
	for(int i = 0; i < n; i++){
		scanf("%s", s[i]);
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'S'){
				sx = i, sy = j;
			} else if(s[i][j] == 'E'){
				ex =i;
				ey = j;
			}
		}
	}
	int p[4] = {0, 1, 2, 3};
	int ans = 0;

	scanf("%s", action);
	int len = strlen(action);



	do{
		int x = sx, y = sy;
		bool ok = 0;
		for(int i = 0; i < len; i++){
			x += dx[p[action[i] - '0']];
			y += dy[p[action[i] - '0']];
			if(x == ex && y == ey){
				ok = 1;
				break;
			}
			if(!valid(x, y)) break;
		}
		ans += ok;
	}while(next_permutation(p, p + 4));
	printf("%d", ans);
}