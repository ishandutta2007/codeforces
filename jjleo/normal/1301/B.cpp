#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];
int L, R;

inline bool check(int x){
	L = 0, R = 1e9;
	for(int i = 1;i <= n;i++){
		if(a[i] != -1){
			if(i > 1 && a[i - 1] != -1) if(abs(a[i] - a[i - 1]) > x) return false;
			if(i < n && a[i + 1] != -1)	if(abs(a[i] - a[i + 1]) > x) return false;
			continue;
		}
		if(a[i - 1] == -1) continue;
		if(i > 1){
			R = min(R, a[i - 1] + x);
			L = max(L, a[i - 1] - x);
		}
		if(L > R) return false;
		if(i < n && a[i + 1] != -1){
			R = min(R, a[i + 1] + x);
			L = max(L, a[i + 1] - x);
		}
		if(L > R) return false;
	}
	return L <= R;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int mx = -1, mn = 1e9;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == -1) continue;
			if(i > 1 && a[i - 1] == -1) mx = max(mx, a[i]), mn = min(mn, a[i]);
			else if(i < n && a[i + 1] == -1) mx = max(mx, a[i]), mn = min(mn, a[i]);
			if(i > 1 && a[i - 1] != -1) ans = max(ans, abs(a[i] - a[i - 1]));
		}
		printf("%d %d\n", max(ans, (mx - mn + 1) / 2), mx + mn >> 1);
		/*int l = 0, r = 1e9, mid;
		while(l < r){
			mid = l + r >> 1; 
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		check(l);
		printf("%d %d\n", l, L);*/
	}
}