#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int x, y;
bool tag[maxn];
int f[maxn], mx[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &x, &y);
		if(x <= n && y <= n) return printf("-1"), 0;
		if(x > y) swap(x, y), tag[x] = true;
		f[x] = y;
	}
	for(int i = n;i;i--) mx[i] = max(mx[i + 1], f[i]);
	int mn = 2 * n, a = 2 * n + 1, b1 = 0, b2 = 0, c = 2 * n + 1, d1 = 0, d2 = 0, ans = 0;
	for(int i = 1;i <= n;i++){
		mn = min(mn, f[i]);
		if(a > c) swap(a, c), swap(b1, d1), swap(b2, d2);
		if(f[i] > a){
			swap(a, c), swap(b1, d1), swap(b2, d2);
			if(f[i] > a) return printf("-1"), 0;
		}
		a = f[i];
		if(tag[i]) b1++;
		else b2++;
		if(mn > mx[i + 1]){
			ans += min(b1 + d2, b2 + d1);
			a = 2 * n + 1, b1 = 0, b2 = 0, c = 2 * n + 1, d1 = 0, d2 = 0;\
		}
	}
	printf("%d", ans);
}