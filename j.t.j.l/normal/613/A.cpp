#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

double sqr(double x){
	return x * x;
}

double x[MAXN], y[MAXN];

double dis(int p, int q){
	return sqrt(sqr(x[p] - x[q]) + sqr(y[p] - y[q]));
}

double Dot(int p, int q, int r){
	return (x[q] - x[p]) * (x[r] - x[p]) + (y[q] - y[p]) * (y[r] - y[p]);
}

double dis2(int p, int q, int r){
	double A = dis(p, q), B = dis(p, r), C = dis(q, r);
	double P = (A + B + C) / 2;
	double tmp = sqrt(P * (P - A) * (P - B) * (P - C)) * 2 / A;
	if (Dot(p, q, r) < 0 || Dot(q, p, r) < 0)
		return min(dis(p, r), dis(q, r));
	else
		return tmp;
}

int main(){
	int n;
	scanf("%d", &n);
	scanf("%lf%lf", &x[0], &y[0]);
	for(int i = 1; i <= n; i++)
		scanf("%lf%lf", &x[i], &y[i]);
	double mx = dis(0, n), mn = dis2(n, 1, 0);
	for(int i = 1; i < n; i++){
		mx = max(mx, dis(0, i));
		mn = min(mn, dis2(i, i+1, 0));
	}
	printf("%.10lf\n", acos(-1) * (sqr(mx) - sqr(mn)));
	return 0;
}