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
set<int> con2[N];
int a[2 * N], b[2 * N];
int main(){
	int n, m;
	sd(n); sd(m);
	for(int i = 1; i <= m; i++){
		sd(a[i]); sd(b[i]); a[i]--;b[i]--;
		con2[a[i]].insert(b[i]);
		con2[b[i]].insert(a[i]);
	}
	// for(int i = 0; i < n; i++) sort(con2[i].begin(), con2[i].end());
	for(int k = 1; k < n; k++){
		if(n % k == 0){
			bool ok = 1;
			for(int i = 1; i <= m; i++){
				int node1 = (a[i] + k) % n, node2 = (b[i] + k) % n;
				if(!con2[node1].count(node2)){
					ok = 0;
					break;
				}
			}
			if(ok){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
}