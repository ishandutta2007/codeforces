// Hydro submission #62cd0768e4874952a08499b3@1657603944594
#include<bits/stdc++.h>
using namespace std;
int n,b[3001]={0},s=0;
int main()
{
	b[1]=1;
	cin>>n;
	for(int i=2;i<=n;i++)
	if(b[i]==0)
	{
		for(int j=2;j*i<=n;j++)
		    b[i*j]++;
	}
	for(int i=1;i<=n;i++)
	if(b[i]==2) s++;
	cout<<s;
	return 0;
}