#include <bits/stdc++.h>
#define maxn 500

using namespace std;

int t;
int n;
char s[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		bool tag = false;
		for(int i = '0';i <= '1' && !tag;i++){
			for(int j = '0';j <= '1' && !tag;j++){
				if(i == j) continue;
				if((s[2][1] != i) + (s[1][2] != i) + (s[n][n - 1] != j) + (s[n - 1][n] != j) <= 2){
					tag = true;
					printf("%d\n", (s[2][1] != i) + (s[1][2] != i) + (s[n][n - 1] != j) + (s[n - 1][n] != j));
					if(s[2][1] != i) printf("%d %d\n", 2, 1);
					if(s[1][2] != i) printf("%d %d\n", 1, 2);
					if(s[n][n - 1] != j) printf("%d %d\n", n, n - 1);
					if(s[n - 1][n] != j) printf("%d %d\n", n - 1, n);
					break;
				}
			}
		}
	}
}