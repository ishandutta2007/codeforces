#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N], c;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		c += (a[i] & 1);
	}
	if(c != 0 && c != n) sort(a, a + n);
	for(int i = 0; i < n; i++) printf("%d ", a[i]);
	puts("");
}