#include<bits/stdc++.h>
using namespace std;
int n, k, name[55], cc;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k-1;i++) name[i] = ++cc;
	for(int i=k;i<=n;i++) {
		char ipt[5];
		scanf("%s",ipt);
		if(ipt[0] == 'N') name[i] = name[i-k+1];
		else name[i] = ++cc;
	}
	for(int i=1;i<=n;i++) {
		if(name[i] <= 25) printf("A%c ",name[i]+'a'-1);
		else printf("B%c ",name[i]+'a'-26);
	}
}