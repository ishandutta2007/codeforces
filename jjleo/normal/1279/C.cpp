#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
int a[maxn], b[maxn];
int x;

long long ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x] = i;
		for(int i = 1;i <= m;i++) scanf("%d", &b[i]);
		ans = x = 0;
		for(int i = 1;i <= m;i++){
			if(a[b[i]] <= x) ans += 1;
			else{
				x = a[b[i]];
				ans += (x - 1 - (i - 1)) * 2 + 1;
			}
		}
		printf("%lld\n", ans);
	}
}