// Hydro submission #6253c063ca5306014671560c@1649669035572
#include<bits/stdc++.h>
#define k(n,i) abs(n-i+1)
#define s(n,i) (n-k(n,i)+1)*2-1
using namespace std;
int main()
{
	int i,j,n;
	cin>>n;
	for(i=1;i<=2*n+1;i++)
	{
		for(j=1;j<=k(n,i)*2;j++)
		printf(" ");
		for(j=1;j<=s(n,i);j++)
		{
			if(j<=(s(n,i))/2)
			printf("%d ",j-1);
			else
			{
			    if(s(n,i)-j>0)
				printf("%d ",s(n,i)-j);
			    else printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}