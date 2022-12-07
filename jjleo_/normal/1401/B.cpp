#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;

int main(){
	scanf("%d", &t);
	int x1, y1, z1, x2, y2, z2;
	while(t--){
		scanf("%d%d%d%d%d%d", &x2, &y2, &z2, &x1, &y1, &z1);
		int ans = 0;
		int x = min(z2, y1);
		ans += x * 2;
		z2 -= x, y1 -= x;
		x = min(z1, x2);
		z1 -= x, x2 -= x;
		x = min(z1, z2);
		z1 -= x, z2 -= x;
		x = min(z1, y2);
		ans -= x * 2;
		printf("%d\n", ans); 
	}
}