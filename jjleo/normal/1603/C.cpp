#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

int t;
int n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int ans = 0, sum = 0;
		for(int i = 1;i <= n;i++){
			b[i] = 1;
			for(int j = i - 1;j;j--){
				if(a[j] == b[j]) break;
				int val = a[j + 1] / b[j + 1];
				if((a[j] + b[j] - 1) / b[j] <= val) break;
				sum = (sum + p - 1ll * (b[j] - 1) * j % p) % p;
				b[j] = a[j] / val;
				while((a[j] + b[j] - 1) / b[j] > val) b[j]++;
				sum = (sum + 1ll * (b[j] - 1) * j) % p;
			}
			ans = (ans + sum) % p;
		}
		printf("%d\n", ans);
	}
}