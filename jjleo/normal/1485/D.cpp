#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int n, m;
int x;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++){
			scanf("%d", &x);
			if((i + j) & 1) printf("%d ", 720720);
			else printf("%d ", 720720 - x * x * x * x);
		}
		puts("");
	}
	
}