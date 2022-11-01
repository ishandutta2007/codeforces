#include <bits/stdc++.h>
#define maxn 100086

using namespace std;	

int n, p;
int a[maxn];
int x, y;

inline int check(int i){
	x = y = 0;
	for(int j = 1;j <= n;j++){
		while(a[x + 1] <= i + j - 1 && x < n) x++, y++;
		if(!y) return 0;
		if(y >= p) return 1;
		y--;
	}
	return 2;
}

int main(){
	scanf("%d%d", &n, &p);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int l = 1, r = 1e9, mid;
	while(l < r){
		mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(!check(l)) return puts("0"), 0;
	int L = l;
	r = 1e9;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(check(mid) == 1) r = mid - 1;
		else l = mid;
	}
	if(check(l) == 1) l--;
	printf("%d\n", l - L + 1);
	for(int i = L;i <= l;i++) printf("%d ", i);
}