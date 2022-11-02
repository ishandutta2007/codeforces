#include<bits/stdc++.h>
using namespace std;

int n, x;
char a[55];


int main()
{
	scanf("%s",a);
	n = strlen(a);
	for(int i=0;i<n;i++) {
		if(a[i] == 'a') x++;
	}
	if(x * 2 > n) printf("%d\n", n);
	else printf("%d\n", 2*x-1);
}