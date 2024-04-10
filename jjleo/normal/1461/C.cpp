#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
int x;
double p;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		int I = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = n;i;i--){
			if(a[i] ^ i){
				I = i;
				break;
			}
		}
		double ans = 1;
		while(m--){
			scanf("%d%lf", &x, &p);
			if(x >= I) ans *= 1 - p;
		}
		printf("%.10f\n", !I ? 1.0 : 1 - ans);
		
	}
}