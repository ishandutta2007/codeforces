#include <bits/stdc++.h>
using namespace std;

int n, p[100010];

int main(){
	scanf("%d", &n);
	puts(n <= 2 ? "1" : "2");
	for(int i = 2; i <= n + 1; i++){
		if(p[i]) continue;
		if(i * i > n + 1) break;
		for(int j = i * i; j <= n + 1; j += i) p[j] = 1;
	}
	for(int i = 2; i <= n + 1; i++) printf("%d ", p[i] + 1);
	return 0;
}