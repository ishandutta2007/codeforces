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

const int N = 51;
int dp[N][N][N];
bool done[N][N][N];
int n, m, h;
int l[N], r[N], x[N], c[N];
vector<int> ind;
int get(int i, int j, int h){
	if(i > j) return 0;
	if(done[i][j][h]) return dp[i][j][h];
	int mx = 0;
	vector<int> indices;
	for(int k = i; k <= j; k++){
		indices.clear();
		for(auto t : ind) if(l[t] <= k && l[t] >= i && r[t] >= k && r[t] <= j){
			indices.push_back(t);
		}
		int penalty = 0;
		int pos = 0;
		for(int a = 0; a <= h; a++){
			while(pos < (int)indices.size() && x[indices[pos]] < a) penalty += c[indices[pos++]];
			mx = max(mx, a * a + get(i, k - 1, a) + get(k + 1, j, a) - penalty);
		}
	}
	done[i][j][h] = 1;
	return dp[i][j][h] = mx;
}
int main(){
	sd(n); sd(h); sd(m);
	for(int i = 1; i <= m; i++) sd(l[i]), sd(r[i]), sd(x[i]), sd(c[i]), ind.push_back(i);
	sort(ind.begin(), ind.end(), [](int i, int j){return x[i] < x[j];});
	printf("%d\n", get(1, n, h));
}