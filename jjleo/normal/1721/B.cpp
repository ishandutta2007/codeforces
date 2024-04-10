#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m, sx, sy, d;

bool check(int x, int y){
	return abs(x - sx) + abs(y - sy) <= d;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d", &n, &m, &sx, &sy, &d);
		bool tag = false;
		for(int i = 1;i <= n && !tag;i++) if(check(i, 1)) tag = true;
		for(int i = 1;i <= m && !tag;i++) if(check(n, i)) tag = true;
		if(!tag){
			printf("%d\n", n + m - 2);
			continue;
		}
		tag = false;
		for(int i = 1;i <= m && !tag;i++) if(check(1, i)) tag = true;
		for(int i = 1;i <= n && !tag;i++) if(check(i, m)) tag = true;
		if(!tag){
			printf("%d\n", n + m - 2);
			continue;
		}
		puts("-1");
	}
}