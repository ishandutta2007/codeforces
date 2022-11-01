#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]); 
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]); 
		sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts("");
		for(int i = 1;i <= n;i++) printf("%d ", b[i]);puts("");
	}
}