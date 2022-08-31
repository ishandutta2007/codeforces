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
ll a[N], b[N];
map<int, vector<int>> mp;
int main(){
	int n; sd(n); 
	for(int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		a[i] = n - 1 - a[i];
		mp[a[i]].push_back(i);
	}

	long long total = 0;
	int now = 0;
	for(auto it : mp){
		if(it.S.size() % (it.F + 1) != 0){
			printf("Impossible\n");
			return 0;
		}
		int num = it.F + 1, times = it.S.size() / num;
		int iter = 0;
		vector<int> v = it.S;
		for(int j = 0; j < times; j++){
			++now;
			for(int t = 0; t < num; t++) b[v[iter++]] = now;
		}
	}
	printf("Possible\n");
	for(int i = 1; i <= n; i++) printf("%lld ", b[i]);
}