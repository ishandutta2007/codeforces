#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

const double pi = acos(-1.0);

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		n <<= 1;
		//printf("%.10lf\n", 2 * 0.5 / tan(pi / n));
		double a = 2 * pi / n * round(n / 8.0);
		printf("%.10lf\n", sin(a) * 0.5 / sin(pi / n) / sin(pi / 4) + sin(pi / 2 - a) * 0.5 / sin(pi / n) / sin(pi / 4));
	}
}