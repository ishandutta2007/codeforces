#include<bits/stdc++.h>
using namespace std;
int n;

int main()
{
	scanf("%d",&n);
	puts("YES");
	for(int i=1;i<=n;i++) {
		int A, B, C, D;
		scanf("%d%d%d%d",&A,&B,&C,&D);
		printf("%d\n",2*abs(A%2)+abs(B%2)+1);
	}
}