#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int x = 0;
		for(int i = 1;i <= k;i++){
			x = -1;
			for(int j = 1;j < n;j++){
				if(a[j] >= a[j + 1]) continue;
				a[j]++;
				x = j;
				break;
			}
			if(x == -1) break;
		}
		printf("%d\n", x);
	}
}