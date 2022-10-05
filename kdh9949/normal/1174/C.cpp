#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N];

int main(){
	scanf("%d", &n);
	for(int i = 2, c = 0; i <= n; i++){
		if(a[i]){ printf("%d ", a[i]); continue; }
		a[i] = ++c;
		for(int j = 2 * i; j <= n; j += i) if(!a[j]) a[j] = c;
		printf("%d ", a[i]);
	}
	puts("");
}