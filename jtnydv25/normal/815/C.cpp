#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>

using namespace std;

#define vi vector<int>
#define sd(s) scanf("%d", &(s))
#define pb push_back 
const int inf = 1e9 + 100;

const int N = 5005;
vi con[N];
void polysum(vi & A, vi & B){
	vi C(A.size() + B.size() - 1);
	for(int i = 0; i < C.size(); i++) C[i] = inf;
	for(int i = 0; i < A.size(); i++)
		for(int j = 0; j < B.size(); j++)
			C[i + j] = min(C[i + j], A[i] + B[j]);
	A = C;	
}

inline int get(vi & A, int i){ return i >= A.size() ? inf : A[i];}

vi takemin(vi & A, vi & B){
	vi C((int)max((int)A.size(), (int)B.size()));
	for(int i = 0; i < C.size(); i++) C[i] = min(get(A, i), get(B, i));
	return C;
}

int c[N], d[N];
vector<int> dp[3][N];

void dfs(int s, int p){
	dp[0][s] = {0, c[s]};
	dp[1][s] = {inf, c[s] - d[s]};
	for(int v : con[s]){
		if(v != p){
			dfs(v, s);
			polysum(dp[1][s], dp[2][v]);
			polysum(dp[0][s], dp[0][v]);
			dp[0][v].clear();
			dp[1][v].clear();
			dp[2][v].clear();
		}
	}
	dp[2][s] = takemin(dp[1][s], dp[0][s]);
}

int main(){
	int n, b, x;
	sd(n); sd(b);
	for(int i = 1; i <= n; i++){
		sd(c[i]); sd(d[i]);
		if(i != 1){
			sd(x);
			con[i].pb(x);
			con[x].pb(i);
		}
	}
	dfs(1, 0);
	int ans = 0;
	for(int i = 0; i < dp[2][1].size(); i++) if(dp[2][1][i] <= b) ans = i;
	printf("%d\n", ans);
}