#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 7;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(x & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int n, x, pos;

int main(){
	scanf("%d%d%d", &n, &x, &pos);
	int l = 0, r = n, mid;
	int a = 0, b = 0;	
	while(l < r){
		mid = l + r >> 1;
		if(mid > pos) r = mid, b++;
		else if(mid < pos) l = mid + 1, a++;
		else l = mid + 1;
	}
	//printf("%d %d--\n", a, b);
	if(a > x - 1 || b > n - x) return printf("0"), 0;
	int ans = 1;
	for(int i = 0;i < a;i++) ans = 1ll * ans * (x - 1 - i) % p;
	for(int i = 0;i < b;i++) ans = 1ll * ans * (n - x - i) % p;
	for(int i = 1;i <= n - a - b - 1;i++) ans = 1ll * ans * i % p;
	printf("%d", ans);
}