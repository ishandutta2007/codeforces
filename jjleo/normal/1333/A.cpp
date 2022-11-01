#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(i == 1 && j == 1) printf("W");
				else printf("B");
			}
			puts("");
		}
	}
}