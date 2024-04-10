#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int c1[4]={};
	for(int i=0;i<4;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			{
				char c;
				cin>>c;
				if(j%2==k%2 && c=='0')c1[i]++;
				if(j%2!=k%2 && c=='1')c1[i]++;
			}
	sort(c1,c1+4);
    cout<<c1[0]+c1[1]+2*n*n-c1[2]-c1[3];
    return 0; 
}