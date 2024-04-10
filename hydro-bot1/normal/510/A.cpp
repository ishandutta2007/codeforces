// Hydro submission #6255058cac286d0a56b85a34@1649739148783
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
    	if(i%2==0) for(j=0;j<m;j++)
    	printf("#");
    	else if(i/2%2)
    	{
    		printf("#");
    		
    		for(j=1;j<m;j++)
    		printf(".");
		}
		else
		{
			for(j=1;j<m;j++)
			printf(".");
			printf("#");
		}
		cout<<endl; 
	}
    return 0;
}