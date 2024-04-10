#include <bits/stdc++.h>
#define maxn 2

using namespace std;

int t;
int n;
int a[maxn], b[maxn];
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		int ans = 0; 
		memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
		scanf("%d", &n);
		for(int i = 0;i < n;i++){
			scanf("%d", &x);
			a[x % 2]++, b[i % 2]++;
			if(x % 2 != i % 2) ans++;
		}
		if(a[0] ^ b[0]) puts("-1");
		else printf("%d\n", ans / 2); 
	}
}