#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;

int n, a[MAXN], b[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++){
		scanf("%d",&b[i]);
	}
	for(int i=n; i; i--){
		a[i] -= a[i-1];
		b[i] -= b[i-1];
	}
	sort(a + 2, a + n + 1);
	sort(b + 2, b + n + 1);
	for(int i=1; i<=n; i++){
		if(a[i] != b[i]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}