#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
double ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) ans += 1.0 / i;
	printf("%.10lf", ans);
}