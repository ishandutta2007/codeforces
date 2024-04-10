#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
		reverse(a + 1, a + 1 + n), reverse(b + 1, b + 1 + n);
	
		int sum = 0, x = 1, y = 1;
		for(int i = 1;i <= n;i++){
			if(a[x] >= b[y] || !k) sum += a[x++];
			else sum += b[y++], k--;
		}
		printf("%d\n", sum);
	}
}