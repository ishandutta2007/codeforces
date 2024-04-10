#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define pd(n) printf("%d\n", n)
const int N = 5e3 + 10;
int P[N], t[N];
double E[N], p[N], F[N], _E[N];
int main(){
	int n, T;
	sd(n); sd(T);
	for(int i = 1; i <= n; i++){
		sd(P[i]); p[i] = P[i]/100.0;
		sd(t[i]);
	}
	for(int i = 1; i <= T; i++){
		double prob = 1.;
		int j = n;
		for(int k = 1; k <= t[j] - 1 && k <= i; k++){
			F[i] += prob * (1 + E[i - k]);
			prob *= 1 - p[j];
		}
	}
	for(int j = n; j >= 1; j--){
		double prob = pow(1 - p[j], t[j] - 1);
		double prob_next = pow(1 - p[j - 1], t[j - 1] - 1);
		for(int i = 1; i <= T; i++) _E[i] = E[i];
		for(int i = 1; i <= T; i++){
			E[i] = p[j] * F[i];
			if(i >= t[j]) E[i] +=  prob * (1 + _E[i - t[j]]);
			F[i] = t[j - 1] == 1 ? 0 : E[i - 1] + 1 + (1 - p[j - 1]) * F[i - 1] - ((i >= t[j - 1]) ? prob_next * (E[i - t[j - 1]] + 1) : 0);
		}
	}
	printf("%.10lf", E[T]);
}