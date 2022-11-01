#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int ans = 0;
		for(int i = 1;i <= 9;i++){
			long long x = i;
			while(x <= n){
				ans++;
				x = x * 10 + i;
			}
		}
		printf("%d\n", ans);
	}
}