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

const int N = 200005;
int c[N];
vector<int> con[N];
const ll INF = 1e18;

ll dp2[N][3], dp[N][3];
ll best[N][4];

bool possible[N][2];

void dfs(int s = 1, int p = -1){
	int num_c = 0;
	dp[s][1] = dp[s][2] = INF;
	multiset<int> ms;
	for(int v : con[s]) if(v != p){
		dfs(v, s);
		dp[s][0] += dp2[v][0];
		ms.insert(dp2[v][1] - dp2[v][0]);
		num_c++;
	}
	auto it = ms.begin();

	for(int i = 0; i < 3; i++){
		if(it == ms.end()){
			best[s][i] = INF;
		} else{
			best[s][i] = *it;
			it++;
		}
	}

	dp[s][1] = dp[s][0] + best[s][0];
	dp[s][2] = dp[s][0] + best[s][0] + best[s][1];

	if(num_c == 0){
		dp[s][0] = INF;
		dp[s][1] = 0;
		dp2[s][0] = c[s];
		dp2[s][1] = 0;
	} else{
		dp2[s][0] = min(dp[s][0], dp[s][1] + c[s]);
		dp2[s][1] = dp[s][1];
	}
}

vector<int> solution;

inline int get(int i, int j, int ignore){
	bool came = 0;
	ll ret = 0;
	int done = 0;
	for(int k = 0; done < j; k++){
		if(!came && best[i][k] == ignore){
			came = 1;
			continue;
		} else{
			done++;
			ret += best[i][k];
		}
	}
	return ret;
}

void go(int s = 1, int p = -1){
	if(s == 1){
		possible[s][0] = 1;
		possible[s][1] = 0;
	}

	if(p != -1){
		if(possible[p][0]){
			if(dp[p][0] == dp2[p][0])
				possible[s][0] = 1;

			if(dp[p][0] + c[p] + get(p, 1, dp2[s][1] - dp2[s][0]) == dp2[p][0])
				possible[s][0] = 1;

			if(dp[p][0] + c[p] + dp2[s][1] - dp2[s][0] == dp2[p][0])
				possible[s][1] = 1;
		}
		if(possible[p][1]){
			if(dp[p][0] +  get(p, 1, dp2[s][1] - dp2[s][0]) == dp2[p][1])
				possible[s][0] = 1;

			// if(dp[p][0] + c[p] + get(p, 2, dp2[s][1] - dp2[s][0]) == dp2[p][1])
			// 	possible[s][0] = 1;

			// if(dp[p][0] + c[p] + get(p, 1, dp2[s][1] - dp2[s][0]) == dp2[p][1])
			// 	possible[s][1] = 1;

			if(dp[p][0] + dp2[s][1] - dp2[s][0] == dp2[p][1])
				possible[s][1] = 1;
		}
	}

	for(int v : con[s]) if(v != p) go(v, s);


	bool ok = 0;
	if(possible[s][0] && dp[s][1] + c[s] == dp2[s][0]) ok = 1;
	// if(possible[s][1] && dp[s][2] + c[s] == dp2[s][1]) ok = 1;
	if(ok) solution.push_back(s);
}

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++) sd(c[i]);
	for(int i = 1; i < n; i++){
		int a, b;
		sd(a); sd(b);
		con[a].push_back(b);
		con[b].push_back(a);
	}
	dfs();
	go();
	printf("%lld %d\n", dp2[1][0], (int)solution.size());
	sort(solution.begin(), solution.end());
	for(auto it : solution) printf("%d ", it);
	printf("\n");
}