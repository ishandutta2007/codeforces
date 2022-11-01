#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, k;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) a[i] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]), a[b[i]]++;
		for(int i = 1;i <= n;i++) a[i] += a[i - 1];
		int ans = n + 1, x = 1, l, r;
		for(int i = 1;i <= n;i++){
			while(x < i && a[i] - a[x] - (n - (a[i] - a[x])) >= k) x++;
			if(a[i] - a[x - 1] - (n - (a[i] - a[x - 1])) >= k && i - x < ans) ans = i - x, l = x, r = i;
		}
		printf("%d %d\n", l, r);
		int sum = 0, cnt = 0, last = 1;
		for(int i = 1;i <= n;i++){
			if(l <= b[i] && b[i] <= r) sum++;
			else sum--;
			if(sum > 0 && cnt < k - 1) printf("%d %d\n", last, i), last = i + 1, cnt++, sum = 0;
		}
		printf("%d %d\n", last, n);
	}
}