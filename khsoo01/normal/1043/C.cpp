#include<bits/stdc++.h>
using namespace std;

int n, ans[1005];

char a[1005];

int main()
{
	scanf("%s",a+1);
	n = strlen(a+1);
	bool rev = false;
	for(int i=n;i>=1;i--) {
		if(rev ^ (a[i] == 'a')) {
			ans[i] = 1;
			rev ^= 1;
		}
	}
	for(int i=1;i<=n;i++) {
		printf("%d ",ans[i]);
	}
}