#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) a[i] = i;
		for(int i = n;i > 1;i -= 2) swap(a[i], a[i - 1]);
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts("");
	}
}