#include<bits/stdc++.h>
using namespace std;
struct hxz{
	long long x,y,z;
};
hxz e[200000];
long long f[1010][1010];
long long n,ans,i,j,value[29999];
bool cmp(hxz a,hxz b)
{
	return a.y>b.y;
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>e[i].x>>e[i].y>>e[i].z;
	sort(e+1,e+n+1,cmp);
	for (i=1;i<=n;i++)
	    {
	    	value[i]=max((long long)0,e[i].x-e[i].y*e[i].z);
	    	f[i][0]=f[i-1][0]+value[i];
	    	for (j=1;j<=i;j++)
	    	    	f[i][j]=max(f[i-1][j]+value[i],f[i-1][j-1]+e[i].x-e[i].y*(j-1));
		}
	ans=0;
	for (i=0;i<=n;i++) ans=max(ans,f[n][i]);
	cout<<ans<<endl;
	return 0;
}