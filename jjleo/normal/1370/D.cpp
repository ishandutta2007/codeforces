#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, k;
int a[maxn];

inline bool check(int x){
	bool tag = true;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(!tag) cnt++, tag = true;
		else if(a[i] <= x) tag = false, cnt++;
	}
	if(cnt >= k) return true;
	tag = false, cnt = 0;
	for(int i = 1;i <= n;i++){
		if(!tag) cnt++, tag = true;
		else if(a[i] <= x) tag = false, cnt++;
	}
	return cnt >= k;
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	int l = 1, r = 1e9, mid;
	while(l < r){
		mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d", l);
}