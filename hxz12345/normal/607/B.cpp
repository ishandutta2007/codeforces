#include<bits/stdc++.h>
using namespace std;
int i,j,f[501][501][3],a[10010],n;
int sc(int t,int w,int x)
{
	if (t>w) return 0;
	if ((t==w)&(x==0)) return 1;
	if ((t==w)&(x==1)) return 0;
	if (f[t][w][x]!=-1) return f[t][w][x];
	int ans,i,y;
	if (x==1)
	    {
	    	ans=1000000000;
	        for (i=t;i<w;i++)
	            {
	            	y=sc(t,i,0)+sc(i+1,w,1);
	            	ans=min(ans,y);
	            	y=sc(t,i,1)+sc(i+1,w,0);
	            	ans=min(ans,y);
				}
			if (a[t]==a[w]) ans=min(ans,sc(t+1,w-1,1));
			f[t][w][x]=ans;
	    }
   else
       {
       	   ans=sc(t,w,1)+1;
       	   for (i=t;i<w;i++)
       	      ans=min(ans,sc(t,i,0)+sc(i+1,w,0));
       	   f[t][w][x]=ans;
	   }
   return f[t][w][x];
}
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++)
	    for (j=1;j<=n;j++)
	        f[i][j][0]=-1,f[i][j][1]=-1;
	cout<<sc(1,n,0)<<endl;
	return 0;
}