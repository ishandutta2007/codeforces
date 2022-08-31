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
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
const int N = 1005;
bool vis[N][N];
int n;
bool go(int b1, int b2, int c1, int c2, int a1, int a2){
	if(vis[b1][b2]) return 0;
	vis[b1][b2] = 1;
	if(b1 == c1 && b2 == c2) return 1;
	if(b1 <= 0 || b2 <= 0 || b1 > n || b2 > n) return 0;
	if(b1 == a1 || b2 == a2 || a1 + a2 == b1 + b2 || a1 - a2 == b1 - b2) return 0;
	for(int i = 0; i < 8; i++) if(go(b1 + dx[i], b2 + dy[i], c1, c2, a1, a2)) return 1;
	return 0;
}

int main(){
	int a1, a2, b1, b2, c1, c2;
	cin >> n >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	cout << (go(b1, b2, c1, c2, a1, a2) ? "YES" : "NO");
}