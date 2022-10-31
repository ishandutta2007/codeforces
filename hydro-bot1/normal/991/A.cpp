// Hydro submission #625922d637de167dd82bd60d@1650008819761
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,n,s,mx;
	cin>>a>>b>>c>>n;
	s=n-a-b+c;
	mx=max(max(a,b),c);
	if(s<=0||mx>=n||c>a||c>b||mx+s>n) 
	printf("-1\n");
	else printf("%d\n",s);
	return 0;
}