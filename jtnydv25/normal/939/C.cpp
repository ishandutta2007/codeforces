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
int a[N];
int bit[N];
void upd(int i, int v){
	i++;
	for(; i < N; i += (i & (-i))) bit[i] += v;
}

int gt(int i){
	i ++;
	int ret = 0;
	for(; i; i -= (i & (-i))) ret += bit[i];
	return ret;
}
int n;
int gt(int i, int j){
	i = max(i, 0);
	j = min(j, n - 1);
	if(i > j) return 0;
	return gt(j) - gt(i - 1);
}

int main(){
	sd(n);
	for(int i = 1; i <= n; i++) sd(a[i]), upd(i - 1, a[i]);
	int s, f;
	sd(s); sd(f); f-=2;s--;
	int mx = 0, ind = 1;
	for(int i = 0; i < n; i++){
		// (i + j) % n >= s, <= f
		// (i + j) >= n, (i + j) >= n + s, (i + j) <= f + s
		int val = gt(s - i, f - i) + gt(n + s - i, n + f - i);
		if(val > mx){
			mx = val;
			ind = i + 1;
		}
	}
	printf("%d\n", ind);
}