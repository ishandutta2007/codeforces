#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	if(m <= 1) puts("1");
	else printf("%d\n", min(n - m, m));
}