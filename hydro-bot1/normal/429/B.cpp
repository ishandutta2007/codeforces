// Hydro submission #62d29d7eb36e4a12382afc91@1657970047161
#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],f1[1001][1001],f2[1001][1001],f3[1001][1001],f4[1001][1001],mx;
int main()
{
	int n,m,mx1,mx2,i,j;cin>>n>>m;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
	cin>>a[i][j];
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
    f1[i][j]=a[i][j]+max(f1[i-1][j],f1[i][j-1]);
    for(i=n;i>0;i--) for(j=m;j>0;j--)
    f2[i][j]=a[i][j]+max(f2[i+1][j],f2[i][j+1]);
    for(i=n;i>0;i--) for(j=1;j<=m;j++)
    f3[i][j]=a[i][j]+max(f3[i+1][j],f3[i][j-1]);
    for(i=1;i<=n;i++) for(j=m;j>0;j--)
    f4[i][j]=a[i][j]+max(f4[i-1][j],f4[i][j+1]);
    for(i=2;i<n;i++) for(j=2;j<m;j++)
    {
		mx1=max(mx,f1[i][j-1]+f2[i][j+1]+f3[i+1][j]+f4[i-1][j]);
    	mx2=max(mx,f1[i-1][j]+f2[i+1][j]+f3[i][j-1]+f4[i][j+1]);
    	mx=max(mx1,mx2);
    }
	printf("%d\n",mx);
    return 0;
}