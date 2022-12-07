#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		if(a[1] + a[2] <= a[n]) printf("%d %d %d\n", 1, 2, n);
		else puts("-1");
	}
}