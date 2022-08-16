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
const int N = 1000006;
int P[N];
void make_cycle(int l, int r){
	for(int i = l; i < r; i++) P[i] = i + 1;
	P[r] = l;
}

int main(){
	int n, a, b;
	sd(n); sd(a); sd(b);
	for(int k = 0; k * a <= n; k++){
		if((n - k * a) % b == 0){
			int k1 = k;
			int k2 = (n - k * a) / b;
			int curr = 1;
			for(int i =1; i <= k1; i++){
				make_cycle(curr, curr + a - 1);
				curr += a;
			}

			for(int i =1; i <= k2; i++){
				make_cycle(curr, curr + b - 1);
				curr += b;
			}
			assert(curr == n + 1);
			for(int i = 1; i <= n; i++) printf("%d ", P[i]);
			return 0;
		}
	}
	printf("-1");
}