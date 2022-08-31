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

int gceil(int a, int b){
	return (a - 1) / b + 1;
}

const int N = 300005;
int c[N];
int perm[N];

int main(){
	int n, x1, x2;
	sd(n); sd(x1); sd(x2);
	for(int i = 1; i <= n; i++){
		scanf("%d", c + i);
		perm[i] = i;
	}
	sort(perm + 1, perm + n + 1, [](int i, int j){return c[i] < c[j];});
	sort(c + 1, c + n + 1);
	// ind1 < ind2
	for(int ind1 = 1; ind1 <= n; ind1++){
		int k1 = gceil(x1, c[ind1]);
		int ind2 = ind1 + k1;
		if(ind2 > n) continue;
		int k2 = gceil(x2, c[ind2]);
		if(ind2 + k2 - 1 <= n){
			printf("Yes\n");
			printf("%d %d\n", k1, k2);
			for(int i = ind1; i <= ind1 + k1 - 1; i++) printf("%d ", perm[i]); printf("\n");
			for(int i = ind2; i <= ind2 + k2 - 1; i++) printf("%d ", perm[i]); printf("\n");
			return 0;
		}
	}

	swap(x1, x2);

	for(int ind1 = 1; ind1 <= n; ind1++){
		int k1 = gceil(x1, c[ind1]);
		int ind2 = ind1 + k1;
		if(ind2 > n) continue;
		int k2 = gceil(x2, c[ind2]);
		if(ind2 + k2 - 1 <= n){
			printf("Yes\n");
			printf("%d %d\n", k2, k1);
			for(int i = ind2; i <= ind2 + k2 - 1; i++) printf("%d ", perm[i]); printf("\n");
			for(int i = ind1; i <= ind1 + k1 - 1; i++) printf("%d ", perm[i]); printf("\n");
			return 0;
		}
	}

	printf("No\n");
}