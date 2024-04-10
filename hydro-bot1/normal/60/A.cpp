// Hydro submission #619465b6a8f5aa929e62d30f@1637115344799
#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,x;
string s[7];
int main() 
{
    scanf("%d%d",&n,&m); // n  m  
	l=1,r=n;
	for(int i=1;i<=m;i++) 
	{
		cin>>s[1]>>s[2]>>s[3]>>s[4];
		scanf("%d",&x);
		if(s[3]=="left") r=min(r,x-1);
		if(s[3]=="right") l=max(l,x+1);
	}
	if(l>r)	printf("-1");
	else printf("%d",r-l+1);
	return 0; 
}