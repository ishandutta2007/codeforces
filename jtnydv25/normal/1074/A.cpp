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

vector<int> hor;
map<int, int> ver;

int getCnt(int x){
	return hor.end() - upper_bound(hor.begin(), hor.end(), x - 1);
}

int main(){
	int n, m; sd(n); sd(m);
	for(int i = 1; i <= n; i++){
		int x;
		sd(x);
		ver[x]++;
	}
	int ans = 0;
	for(int i = 1; i <= m; i++){
		int x1, x2, y; sd(x1); sd(x2); sd(y);
		if(x1 != 1) continue;
		if(x2 == 1e9){
			ans++;
		} else
		hor.push_back(x2);
	}

	sort(hor.begin(), hor.end());
	int f = n;
	int sm = 0;
	for(auto it : ver){
		f = min(f, sm + getCnt(it.F));
		sm += it.S;
	}

	printf("%d\n", ans + f);
}