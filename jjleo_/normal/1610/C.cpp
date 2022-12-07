#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn], b[maxn];

bool check(int x){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(cnt <= b[i] && x - cnt - 1 <= a[i]) cnt++;
		if(cnt == x) return true;
	}
	return cnt == x;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d%d", &a[i], &b[i]);
		int l = 0, r = n, mid;
		check(1);
		while(l < r){
			mid = (l + r >> 1) + 1;
			if(check(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
	}
}