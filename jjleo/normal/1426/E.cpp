#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a1, a2, a3, b1, b2, b3;

/*inline void mn(int a1, int a2, int a3, int b1, int b2, int b3){
	int ans = n;
	int x = min(b1, a2);
	b1 -= x, a2 -= x, ans -= x;
	x = min(b2, a3);
	b2 -= x, a3 -= x, ans -= x;
	x = min(b3, a1);
	b3 -= x, a1 -= x, ans -= x;
	ans -= min(a1, b1) + min(a2, b2) + min(a3, b3); 
	printf("%d %d %d %d %d %d--\n", a1, a2, a3, b1, b2, b3);
	printf("%d", ans);
}*/

inline void mn(int a1, int a2, int a3, int b1, int b2, int b3){
	printf("%d", max(0, max(b1 - a1 - a2, max(b2 - a2 - a3, b3 - a3 - a1))));
}

inline void mx(int a1, int a2, int a3, int b1, int b2, int b3){
	int ans = 0;
	int x = min(a1, b2);
	a1 -= x, b2 -= x, ans += x;
	x = min(a2, b3);
	a2 -= x, b3 -= x, ans += x;
	x = min(a3, b1);
	a3 -= x, b1 -= x, ans += x;
	printf("%d", ans);
}

int main(){
	scanf("%d%d%d%d%d%d%d", &n, &a1, &a2, &a3, &b1, &b2, &b3);
	mn(a1, a2, a3, b1, b2, b3);
	printf(" ");
	mx(a1, a2, a3, b1, b2, b3);
}