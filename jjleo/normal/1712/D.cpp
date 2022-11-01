#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int a[maxn];

bool check(int mid){
	int cnt = 0;
	for(int i = 1;i <= n;i++) cnt += a[i] * 2 < mid;
	bool tag = false;
	for(int i = 1;i < n;i++) if(min(a[i] * 2 < mid ? 1000000000 : a[i], a[i + 1] * 2 < mid ? 1000000000 : a[i + 1]) >= mid) tag = true;
	if(!tag){
		for(int i = 1;i < n;i++) if(max(a[i] * 2 < mid ? 1000000000 : a[i], a[i + 1] * 2 < mid ? 1000000000 : a[i + 1]) >= mid) tag = true;
		if(tag) cnt++;
		else cnt += 2;
	}
	return cnt <= k;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int l = 0, r = 1e9, mid;
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
	}
}