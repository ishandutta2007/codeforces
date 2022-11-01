#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

int t, n;
int a[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) scanf("%d", &a[i][j]);
		int ans = 0, last = 0;
		for(int J = 1;J <= n;J += 2){
			int sum = last;
			for(int i = 1, j = J;j >= 1;i += 2, j -= 2){
				sum ^= a[i][j];
			}
			ans ^= sum, last = sum;
		}
		for(int I = 2;I <= n;I += 2){
			int sum = last;
			for(int j = n, i = I;i <= n;i += 2, j -= 2){
				sum ^= a[i][j];
			}
			ans ^= sum, last = sum;
		}
		last = 0;
		for(int J = n;J >= 1;J -= 2){
			int sum = last;
			for(int i = 1, j = J;j <= n;i += 2, j += 2){
				sum ^= a[i][j];
			}
			ans ^= sum, last = sum;
		}
		for(int I = 2;I <= n;I += 2){
			int sum = last;
			for(int j = 1, i = I;i <= n;i += 2, j += 2){
				sum ^= a[i][j];
			}
			ans ^= sum, last = sum;
		}
		printf("%d\n", ans);
	}
}