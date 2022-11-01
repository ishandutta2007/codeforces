#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m;
int x, y, k;
long long ans;
int a[maxn], b[maxn];

int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &x, &k, &y);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= m;i++) scanf("%d", &b[i]);
	int j = 0;
	for(int i = 1;i <= n && j < m;i++){
		if(a[i] == b[j + 1]) j++;
	}
	if(j < m) return printf("-1"), 0;
	int l = 1, r = 0, i = 1;
	j = 0;
	while(i <= m){
		j = max(j, a[r + 1]);
		//printf("%d %d--\n", l, r);
		if(b[i] == a[r + 1]){
			if(l <= r){
				int len = r - l + 1;
				if(len < k && a[l - 1] != j && a[r + 1] != j) return printf("-1"), 0;
				long long sum = 1ll * len / k * x + 1ll * len % k * y; 
				if(a[l - 1] != j && a[r + 1] != j){
					sum = min(sum, x + 1ll * (len - k) * y);
				}else{
					sum = min(sum, 1ll * len * y);
				}
				ans += sum;
			}
			r++, l = r + 1; 
			i++;
			j = a[r];
		}else{
			r++;
		}
	}
	if(l <= n){
		j = a[l - 1];
		for(int i = l;i <= n;i++) j = max(a[i], j);
		int len = n - l + 1;
		if(len < k && a[l - 1] != j) return printf("-1"), 0;
		long long sum = 1ll * len / k * x + 1ll * len % k * y; 
		if(a[l - 1] != j){
			sum = min(sum, x + 1ll * (len - k) * y);
		}else{
			sum = min(sum, 1ll * len * y);
		}
		ans += sum;
	}
	printf("%lld", ans);
	
}