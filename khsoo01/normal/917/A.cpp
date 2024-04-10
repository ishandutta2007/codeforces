#include<bits/stdc++.h>
using namespace std;

int n, ans, dt[5005];

char a[5005];

void solve (int X) {
	for(int i=X, M=0, C=0; i<=n; i++) {
		a[i] == '(' ? C-- : C++;
		if(M <= C) {M = C; dt[C]++;}
	}
	for(int i=X-1, M=0, C=0; i>=1; i--) {
		a[i] == '(' ? C++ : C--;
		if(M <= C) {M = C; ans += dt[C];}
	}
	for(int i=0;i<=n;i++) dt[i] = 0;
}

int main()
{
	scanf("%s",a+1);
	n = strlen(a+1);
	for(int i=1;i<=n;i++) {
		if(a[i] == '?') {
			solve(i);
			a[i] = '(';
		}
	}
	for(int i=1;i<=n;i++) {
		int C = 0;
		for(int j=i;j<=n;j++) {
			a[j] == '(' ? C++ : C--;
			if(C < 0) break;
			if(C == 0) ans++;
		}
	}
	printf("%d\n",ans);
}