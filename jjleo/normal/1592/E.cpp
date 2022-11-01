#include <bits/stdc++.h>
#define maxn 1100086

using namespace std;

int n;
int a[maxn];
int l[maxn], r[maxn];
int mx[2][maxn], sum[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	int ans = 0;
	memset(mx, -1, sizeof(mx));
	for(int b = 0;b <= 20;b++){
		int last = 0;
		mx[0][0] = 0;
		for(int i = 1;i <= n;i++){
			sum[i] = sum[i - 1] ^ (a[i] >> (b + 1) << (b + 1));
			if(!(a[i] & (1 << b))){
				for(int j = last;j < i;j++) mx[j & 1][sum[j]] = -1;
				last = i;
				if(mx[i & 1][sum[i]] == -1) mx[i & 1][sum[i]] = i;
				continue;
			}
			if(mx[i & 1][sum[i]] != -1) ans = max(ans, i - mx[i & 1][sum[i]]);
			if(mx[i & 1][sum[i]] == -1) mx[i & 1][sum[i]] = i;
		}
		for(int i = last;i <= n;i++) mx[i & 1][sum[i]] = -1;
	}
	printf("%d\n", ans);	
}