#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, s;
int a[maxn];
long long sum;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &s);
		int id = 0;
		sum = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]), sum += a[i];
			if(sum <= s) id = i;
		}
		if(id == n){
			puts("0");
			continue;
		}
		int x = 0, y = 0; 
		for(int i = 1;i <= id + 1;i++){
			if(a[i] >= x) x = a[i], y = i;
		}
		printf("%d\n", y);
	}
}