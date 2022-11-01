#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		for(int i = n;i;i--) printf("%d ", a[i]);
		puts(""); 
	}
}