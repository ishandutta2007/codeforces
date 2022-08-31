#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
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
int f[N];
int main(){
	int n;
	sd(n);	
	for(int i = 1; i <= n; i++){
		int x;
		sd(x);
		f[x]++;
	}
	for(int i = 0; i < N; i++) if(f[i] & 1){
		printf("Conan\n");
		return 0;
	}
	printf("Agasa\n");
}