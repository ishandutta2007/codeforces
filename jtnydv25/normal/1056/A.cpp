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

bitset<101> lines;

int main(){
	for(int i = 0; i <= 100; i++) lines[i] = 1;
		int n; sd(n);
	for(int i = 1; i <= n; i++){
		int r; sd(r);
		bitset<101> bs;
		for(int j = 0; j < r; j++){
			int k; sd(k);	bs[k] = 1;
		}
		lines &= bs;
	}
	// int cnt = lines.count();
	// print
	for(int i = 1; i  <= 100; i++) if(lines[i]) printf("%d ", i);
}