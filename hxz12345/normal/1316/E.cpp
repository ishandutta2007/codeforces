#include<bits/stdc++.h>
using namespace std;
struct hxz{
	long long x,id;
};
hxz a[100010];
long long b[100010][10],c[100010][10];
int d[200000];
long long len[200000],f[100010][300];
bool exist[200000];
int path[3][129][8];
long long k,now,status,final,m,p,ans,sum,n,i,j;
bool cmp(hxz a,hxz b)
{
	return a.x>b.x;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>n>>p>>m;
	for (i=1;i<=n;i++)   
	     {
	     	cin>>a[i].x;a[i].id=i;
		 }
	for (i=1;i<=(1<<p)-1;i++)
	    {
	    	 j=i;
	    	 for (;j;j>>=1)
	    	    len[i]+=(j&1);
		}
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++) d[a[i].id]=i;
	for (i=1;i<=n;i++)
	    {
	    	for (j=1;j<=p;j++)
               {
 	    	   cin>>b[d[i]][j];
 	    	   c[d[i]][j]=b[d[i]][j];
 	           }
	    }
    int l;
    final=(1<<p)-1;
    for (i=0;i<=n;i++)
       for (j=1;j<=final;j++)
          f[i][j]=-1000000000000;
    for (i=1;i<=n;i++)
        {
        	for (j=0;j<=final;j++) f[i][j]=f[i-1][j];
        	for (status=0;status<=final;status++)
        	     {
				 	if (i<=len[status]+m)
                      f[i][status]=max(f[i][status],f[i-1][status]+a[i].x);
        	     for (j=1;j<=p;j++)
        	        if ((status & (1<<(j-1)))==0)
        	            {
        	            	now=status | (1<<(j-1));
        	            	f[i][now]=max(f[i][now],f[i-1][status]+c[i][j]);
						}
			    }
	     }
	for (i=1;i<=n;i++) ans=max(ans,f[i][final]);
	cout<<ans<<endl;
	return 0;
}