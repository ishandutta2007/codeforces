#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, d;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &d);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 2;i <= n && d;i++){
			int x = min(a[i], d / (i - 1));
			a[1] += x, d -= x * (i - 1);
		}
		printf("%d\n", a[1]);
	}
}