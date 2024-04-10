#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	printf("%d\n", (n - 1) / 2);
	int l = 1, r = n;
	for(int i = 1;i <= n;i++){
		if(i & 1) printf("%d ", a[r--]);
		else printf("%d ", a[l++]);
	}	
}