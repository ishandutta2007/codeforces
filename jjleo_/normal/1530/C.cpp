#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], b[maxn];

inline bool check(int k){
	int cnt = (n + k) - (n + k) / 4;
	int sum1 = min(cnt, k) * 100 + a[cnt - min(cnt, k)];
	int sum2 = b[min(n, cnt)];
	return sum1 >= sum2;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		sort(a + 1, a + 1 + n, greater<int>()), sort(b + 1, b + 1 + n, greater<int>());
		for(int i = 1;i <= n;i++) a[i] += a[i - 1], b[i] += b[i - 1];
		int l = 0, r = 1e6, mid;
		while(l < r){
			mid = l + r >> 1;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
}