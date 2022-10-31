// Hydro submission #62550663ac286d0a56b85c71@1649739364332
#include<bits/stdc++.h>
using namespace std;
bool f[501][501];
int main()
{
    int n,m,q,i,j,k,x,y,s,mx;
	cin>>n>>m>>q;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	cin>>f[i][j];
	for(k=1;k<=q;k++)
	{
		mx=0;
		cin>>x>>y;
		f[x][y]=!f[x][y];
		for(i=1;i<=n;i++)
		{
			s=0;
			for(j=1;j<=m;j++)
			{
				if(f[i][j]) s++;
				else s=0;
				mx=max(mx,s);
			}
		}
		printf("%d\n",mx);
	}
	return 0;
}