#include <bits/stdc++.h>
#include <string>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int x,y,z,X=0,Y=0,Z=0;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>z;
		X+=x;
		Y+=y;
		Z+=z;		
	}	
	if(X==0 && Y==0 && Z==0)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}