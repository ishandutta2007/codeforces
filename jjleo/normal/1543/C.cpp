#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
double c, m, p, v;

double dfs(double c, double m, double p){
	double ans = 1, mn;
	if(fabs(p - 1) < 1e-5) return ans;
	if(fabs(c) > 1e-5){
		mn = min(v, c);
		if(fabs(m) > 1e-5) ans += c * dfs(c - mn, m + mn / 2, p + mn / 2);
		else ans += c * dfs(c - mn, m, p + mn);
	}
	if(fabs(m) > 1e-5){
		mn = min(v, m);
		if(fabs(c) > 1e-5) ans += m * dfs(c + mn / 2, m - mn, p + mn / 2);
		else ans += m * dfs(c, m - mn, p + mn);
	}
	return ans;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lf%lf%lf%lf", &c, &m, &p, &v);
		printf("%.10f\n", dfs(c, m, p));
	}
}