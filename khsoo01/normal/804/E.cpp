#include<bits/stdc++.h>
using namespace std;
int n;

void add (int A, int B) {
	if(A+B > n) {
		printf("%d %d\n", A, B);
	}
	else if((A+B)%4 == 1) {
		add(A, A+B);
		printf("%d %d\n", A, B);
		add(B, A+B);
	}
	else if((A+B)%4 == 2) {
		add(A, A+B);
		add(A, A+B+1);
		add(A, A+B+2);
		printf("%d %d\n", A, B);
		add(B, A+B+2);
		add(B, A+B+1);
		add(B, A+B);
	}
	else {
		printf("%d %d\n", A, B);
	}
}

int main()
{
	scanf("%d",&n);
	if(n%4 > 1) {puts("NO"); return 0;}
	puts("YES");
	for(int i=1;i<=n/4;i++) {
		int X = 4*i, piv = 2*i-1;
		add(X-2, X-1); add(piv, X-2);
		add(X-1, X); add(piv, X-1);
		add(X-2, X); add(piv, X);
	}
}