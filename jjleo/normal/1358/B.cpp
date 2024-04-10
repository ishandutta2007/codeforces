#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x = n + 1;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		for(int i = n;i;i--){
			if(a[i] > x - 1) x--;
		}
		printf("%d\n", x);
	}
}