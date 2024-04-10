#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		bool tag = false;
		for(int i = 1;i < n;i++) if(a[i] > a[i + 1]) tag = true;
		if(!tag){
			puts("0");
			continue;
		}
		if(a[n - 1] > a[n] || a[n] < 0){
			puts("-1");
			continue;
		}
		printf("%d\n", n - 2);
		for(int i = 1;i < n - 1;i++) printf("%d %d %d\n", i, n - 1, n);
	}
}