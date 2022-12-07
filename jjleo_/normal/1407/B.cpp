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
		sort(a + 1, a + 1 + n, greater<int>());
		int x = a[1];
		printf("%d ", x), a[1] = 0;
		for(int t = 1;t < n;t++){
			int mx = 0, j = 0;
			for(int i = 1;i <= n;i++){
				if(!a[i]) continue;
				if(__gcd(a[i], x) > mx) j = i, mx = __gcd(a[i], x);
			}
			printf("%d ", a[j]), a[j] = 0, x = mx;
		}	
		
		puts("");
	}
}