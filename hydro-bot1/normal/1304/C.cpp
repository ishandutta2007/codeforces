// Hydro submission #6257a0f2ac286d0a56ba9967@1649910003748
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,t,f,s,mx,mn,i,x,y,z;
	cin>>t; 
	while(t--)
	{
		f=1;
		cin>>n>>m;
		s=0,mx=m,mn=m;
		for(i=1;i<=n;i++)
		{
			x,y,z;
			cin>>x>>y>>z;
			if(!f) continue;
			mx+=x-s;
			mn-=x-s;
			if(mx<y||mn>z) f=0;
			if(mx>z) mx=z;
			if(mn<y) mn=y;
			s=x;
 		}
 		printf(f?"YES\n":"NO\n");
	}
	return 0;
}