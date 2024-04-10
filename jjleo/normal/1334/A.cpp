#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int x, y, a, b;
bool suc;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a = b = 0;
		suc = true;
		for(int i = 1;i <= n;i++){
			scanf("%d%d", &x, &y);
			if(x < a || y < b || (x - a < y - b)) suc = false;
			a = x, b = y;
		}
		puts(suc ? "YES" : "NO");
	}
}