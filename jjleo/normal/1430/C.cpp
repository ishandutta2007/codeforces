#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int ans = n;
		for(int i = n - 1;i;i--) ans = (ans + i + 1) / 2;
		printf("%d\n", ans);
		ans = n;
		for(int i = n - 1;i;i--) printf("%d %d\n", ans, i), ans = (ans + i + 1) / 2;
	}
}