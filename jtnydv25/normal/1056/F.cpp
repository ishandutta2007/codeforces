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

const int N = 105;

const int MAXP = 1005;

double dp[N][MAXP], dp1[N][MAXP];

int a[N], p[N], perm[N];
const double INF = 1e18;

int main(){
	int t; sd(t);
	while(t--){
		int n; sd(n);

		double C, T; 
		scanf("%lf %lf", &C, &T);

		int sum_p = 0;

		for(int i = 1; i <= n; i++){
			sd(a[i]); sd(p[i]);
			sum_p += p[i];
			perm[i] = i;
		}

		sort(perm + 1, perm + n + 1, [](int i, int j){return a[i] > a[j];});

		dp[0][0] = 0;
		for(int j = 1; j < MAXP; j++) dp[0][j] = INF;

		for(int i = 1; i < N; i++)
			for(int j = 0; j < MAXP; j++) dp[i][j] = INF;


		int ans = 0;

		for(int i = 1; i <= n; i++){
			int ind = perm[i];
			for(int j = 0; j < i; j++)
				for(int k = 0; k <= 10*j; k++) dp1[j][k] = dp[j][k];

			double alpha = 1. / 0.9;
			double curr_coeff = alpha;

			for(int old_j = 0; old_j < i; old_j++, curr_coeff *= alpha){
				for(int old_s = 0; old_s <= 10 * old_j; old_s++){
					dp[old_j + 1][old_s + p[ind]] = min(dp[old_j + 1][old_s + p[ind]],
						dp1[old_j][old_s] + a[ind] * curr_coeff);
				}
			}
			if(i == n){
				for(int j = 1; j <= n; j++)
					for(int P = 1; P <= sum_p; P++){
						double ws = dp[j][P];
						if(ws >= 1e15) continue;
						double t = max(0., (sqrt(C * ws) - 1)/C);
						double mx =t + 10 * j + ws / (1 + C * t);
						// trace(ws, t, P, mx, T);s
						if(mx <= T){
							ans = max(ans, P);
						}
					}
			}
		}
		printf("%d\n", ans);
	}
}