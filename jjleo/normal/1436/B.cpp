#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int t;
int n;
int a[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++){
			a[i][i] = a[i][i + 1] = 1;
		}
		a[n][1] = 1;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) printf("%d ", a[i][j]);
			puts("");
		}
	}
}