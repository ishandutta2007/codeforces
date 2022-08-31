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
int E[N];
struct rational{
	int num, den;
	rational(){}
	rational(int _num, int _den){
		num = _num; den = _den;
	}
	bool operator < (const rational & R)const{
		return num * 1ll * R.den < den * 1ll * R.num;
	}
	void print(){
		printf("%.15lf\n", num / (double) den);
	}
};
int main(){
	int n, U;
	sd(n); sd(U);
	for(int i = 1; i <= n; i++){
		sd(E[i]);
	}
	rational ans = rational(-1, 1);
	for(int i = 1; i <= n;i++){
		int ei = E[i], ej = E[i + 1];
		int ind = upper_bound(E + 1, E + n + 1, ei + U) - E;
		ind--;
		if(ind <= i + 1) continue;
		int ek = E[ind];
		rational curr = rational(E[ind] - ej, E[ind] - ei);
		if(ans < curr){
			ans = curr;
		}
	}
	if(ans.num == -1){
		printf("-1\n");
		return 0;
	}
	ans.print();
}