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
const int N = 1005;
int a[N];
int x[N];
bool done[N];
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	vector<int> ans;
	for(int k = 1; k <= n; k++){
		memset(done, 0, sizeof done);
		bool ok = 1;
		for(int i = 1; i <= n; i++){
			if(done[(i - 1) % k] && x[(i - 1) % k] != a[i] - a[i - 1]){
				ok = 0;
				break;
			}
			done[(i - 1) % k] = 1;
			x[(i - 1) % k] = a[i] - a[i - 1];
		}
		if(ok) ans.push_back(k);
	}
	printf("%d\n", (int) ans.size());
	for(auto it : ans) printf("%d ", it);
}