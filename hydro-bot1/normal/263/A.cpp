// Hydro submission #6253c979ca530601467164ed@1649658233856
#include<bits/stdc++.h>
using namespace std;
int m[5][5];
int main()
{
	int i,j,a,b,c,mn=4;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	cin>>m[i][j];
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
	if(m[i][j])
	{
		a=abs(i-2),b=abs(j-2),c=abs(i-j); 
		if(!a&&!b) 
		mn=min(0,mn); 
		else if(!a&&b==1||!b&&a==1)
		mn=min(1,mn);
		else if(i+j==2||i+j==6||c==2)
		mn=min(2,mn);
		else if(i+j==1||i+j==7||c==3)
		mn=min(3,mn);
	}
	printf("%d\n",mn);
    return 0;
}