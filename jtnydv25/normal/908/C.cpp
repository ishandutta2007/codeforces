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

const double EPS = 1e-8;
const double INF = 1e18;

double func(double x, double r1, double r2){
	if(r1 + r2 < x - EPS) return -INF;
	if(r1 + r2 < x + EPS) return 0;
	return sqrt((r1 + r2) * (r1 + r2) - x * x);
}
int x[1005];
double y[1005];
int main(){
	int n, r;
	sd(n); sd(r);
	for(int i = 1; i <= n; i++){
		sd(x[i]);
		y[i] = r;
		for(int j = 1; j < i; j++)
			y[i] = max(y[i], y[j] + func(abs(x[i] -x[j]), r, r));
		printf("%.10lf ", y[i]);
	}
}