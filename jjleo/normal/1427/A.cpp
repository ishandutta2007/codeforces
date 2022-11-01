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
		int sum = 0;
		for(int i = 1;i <= n;i++) sum += a[i];
		if(sum == 0) puts("NO");
		else{
			if(sum > 0) sort(a + 1, a + 1 + n, greater<int>());
			else sort(a + 1, a + 1 + n);
			puts("YES");
			for(int i = 1;i <= n;i++) printf("%d ", a[i]);
			puts("");
		}
	}
}