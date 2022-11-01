#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		int sum = 0;
		for(int i = 1;i <= n;i++) sum += a[i] - b[i];
		sum = abs(sum);
		int val = 0;
		for(int i = 1;i <= n;i++) val += a[i] ^ b[i];
		if(val == sum) printf("%d\n", sum);
		else printf("%d\n", sum + 1);
	}
}