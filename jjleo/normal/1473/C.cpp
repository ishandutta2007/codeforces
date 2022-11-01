#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= k;i++) a[i] = i;
		reverse(a + k - (n - k), a + k + 1);
		for(int i = 1;i <= k;i++) printf("%d ", a[i]);
		puts("");
	}
}