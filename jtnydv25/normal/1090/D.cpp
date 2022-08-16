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
set<int> con[N];

int A[N], B[N];

int main(){
	int n, m; sd(n); sd(m);
	if(n == 1 || 2 * m == (n * (ll) (n - 1))){
		printf("NO\n");
		return 0;
	}
	for(int i = 1; i <= m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		con[a].insert(b);
		con[b].insert(a);
	}

	for(int i = 1; i <= n; i++) if(con[i].size() != n - 1){
		for(int j = 1; j <= n; j++) if(j != i && !con[i].count(j)){
			// i, j -> (1, 1) in B, (1, 2) in A
			A[i] = 1; A[j] = 2;
			B[i] = B[j] = 1;
			int v = 2;
			for(int k = 1; k <= n; k++){
				if(k != i && k != j){
					A[k] = ++v;
					B[k] = v;
				}
			}
			printf("YES\n");
			for(int i = 1; i <= n; i++) printf("%d ", A[i]); printf("\n");
			for(int i = 1; i <= n; i++) printf("%d ", B[i]); printf("\n");
				return 0;
		}
	}
}