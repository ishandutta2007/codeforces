#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x, y;
int a, b, mn;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &x, &y);
		mn = 1e9;
		for(int i = 1;i <= 50;i++){
			for(int j = 1;j <= 50;j++){
				if(x - i >= 0 && (x - i) % j == 0 && (x - i) / j < n && y - i >= 0 && (y - i) % j == 0 && (y - i) / j < n){
					if(mn > i + j * (n - 1)){
						mn = i + j * (n - 1), a = i, b = j;
					}
				}
			}
		}
		for(int i = 0;i < n;i++) printf("%d ", a + b * i);
		puts("");
	}
}