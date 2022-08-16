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
const int N = 400005;
int p[N], a[N];
int main(){
	p[0] = p[1] = 1;
	for(int i = 2; i * i < N; i++) if(!p[i])
		for(int j = i * i; j < N; j += i) p[j] = 1;
	int n1 = 0, n2 = 0, n;
	int f[3] = {0, 0, 0};
	sd(n);
	for(int i = 1; i <= n; i++) sd(a[i]), f[a[i]]++;
	int x = 0;
	for(int i = 1; i <= n; i++){
		if((f[1] && !p[x + 1]) || !f[2]){
			x += 1;
			printf("%d ", 1);
			f[1]--;
		} else{
			x+=2;
			printf("%d ", 2);
			f[2]--;
		}
	}
}