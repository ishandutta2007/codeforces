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
int a[N], perm[N];
const int K = 105;
bool done[N];
int ans[N];
bool st[K][K];

void add(int pos){
	done[pos] = 1;
	if(ans[pos] == 0){
		for(int k = 1; k < K; k++) st[k][pos % k] = 1;
	}
}

int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++) sd(a[i]), perm[i] = i;
	sort(perm + 1, perm + n + 1, [](int i, int j){return a[i] > a[j];});
	
	for(int i = 1; i <= n;){
		int beg = i; i++;
		while(i <= n && a[perm[i]] == a[perm[beg]]) i++;
		// beg .. i-1
		for(int j = beg; j < i; j++){
			int ind = perm[j];
			if(a[ind] < K){
				int md = ind % a[ind];
				ans[ind] = st[a[ind]][md];
			} else{
				for(int k = ind + a[ind]; k <= n; k += a[ind]) if(done[k] && !ans[k]) ans[ind] = 1;
				for(int k = ind - a[ind]; k >= 1; k -= a[ind]) if(done[k] && !ans[k]) ans[ind] = 1;
			}
		}

		for(int j = beg; j < i; j++) add(perm[j]);
	}

	for(int i = 1; i <= n; i++) printf("%c", ans[i] ? 'A' : 'B');
}