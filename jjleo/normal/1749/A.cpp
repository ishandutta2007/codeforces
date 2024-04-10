#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++){
			int x, y;
			scanf("%d%d", &x, &y);
		}
		puts(n > m ? "YES" : "NO");
	}
}