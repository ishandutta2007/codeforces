#include<bits/stdc++.h>
using namespace std;

int n, m;

char a[200005], b[200005];

int main()
{
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
	bool F = false;
	for(int i=1;i<=n;i++) {
		if(a[i] == '*') F = true;
	}
	if(!F) {
		if(n != m) {
			puts("NO");
			return 0;
		}
		for(int i=1;i<=n;i++) {
			if(a[i] != b[i]) {puts("NO"); return 0;}
		}
		puts("YES");
		return 0;
	}
	if(n > m+1) {puts("NO"); return 0;}
	for(int i=1;i<=n;i++) {
		if(a[i] == '*') break;
		if(a[i] != b[i]) {puts("NO"); return 0;}
	}
	for(int i=1;i<=n;i++) {
		if(a[n-i+1] == '*') break;
		if(a[n-i+1] != b[m-i+1]) {puts("NO"); return 0;}
	}
	puts("YES");
}