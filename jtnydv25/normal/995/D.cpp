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
const int N = 1 << 20;
int f[N];
int main(){
	int n, r; 
	sd(n); sd(r);
	long long sm = 0;
	for(int i = 0; i < (1 << n); i++) sd(f[i]), sm += f[i];
	for(int i = 0; i <= r; i++){
		printf("%.10lf\n", sm *1. / (1 << n));
		int z, g; 
		if(i != r){
			sd(z); sd(g);
			sm += g - f[z];
			f[z] = g;
		}
	}
}