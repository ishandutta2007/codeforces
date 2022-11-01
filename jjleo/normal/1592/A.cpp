#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, h;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &h);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int mn = h / (a[n] + a[n - 1]) * 2;
		if(h % (a[n] + a[n - 1])) if(h % (a[n] + a[n - 1]) <= a[n]) mn++;
		else mn += 2;
		printf("%d\n", mn);
	}
}