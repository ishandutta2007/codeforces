#include<bits/stdc++.h>
using namespace std;
struct hxz{
	int x,y;
};
hxz c[2000];
long long g[100][100],edge[300][300],f[20000000],e[100][100],a[1000],b[1000];
int kkk,w,u[100000],path_x[20000000],path[20000000],path_y[20000000],path_k[20000000],x,final,a0,b0,n,i,j,k;
long long ans;
bool cmp(hxz a,hxz b)
{
	return a.y>b.y;
}
void sc(int status)
{
	/*int z=f[final^status];
	if (z!=1000000000)
	    {
	    	f[final]=min(f[final],f[status]+f[final^status]);
	    	ans=min(ans,f[final]);
	    	if (f[status]+z>ans) return;
		}
	if (f[status]>ans) return;*/
	int i,j,y,k,xx,yy,now,tot,flag=false;
	for (i=n;i>=1;i--)
	    if ((status & (1<<(i-1)))==0) 
	        {
			tot=0;
	        for (j=1;j<=edge[i][0];j++)
	             {
				 k=edge[i][j];
				 if ((status & (1<<(k-1)))!=0) continue;
	       	     y=status | (1<<(i-1));y=y|(1<<(k-1));
	       	     xx=g[i][k];yy=e[i][0]*2+e[k][0]*2;now=1;
	       	     if (xx>yy) 
	       	         {
	       	         	xx=yy;now=2;
				     }
	       	     if (f[status]+xx<f[y])
	       	                 {
	       	            	 f[y]=f[status]+xx;
	       	            	 path[y]=status;path_x[y]=i;path_y[y]=k;path_k[y]=now;
	       	            	 sc(y);
	       	            	 flag=true;
						     }
					break;
		        }
		}
	/*for (i=1;i<=n;i++)
	    if ((status & (1<<(i-1)))==0) 
	         {
	       	      y=status | (1<<(i-1));
	       	      if (f[status]+e[0][i]+e[i][0]<f[y])
	       	            {
	       	            	f[y]=f[status]+e[0][i]+e[i][0];
	       	            	sc(y);
						   }
		          }*/
}
int main()
{
	cin>>a0>>b0;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i]>>b[i];
	//for (i=1;i<=n;i++) c[i].x=a[i],c[i].y=b[i];
	//sort(c+1,c+n+1,cmp);
    for (i=1;i<=n;i++)
       for (j=1;j<=n;j++)
           e[i][j]=(a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]);
    for (i=1;i<=n;i++)
        {
        	e[0][i]=(a[i]-a0)*(a[i]-a0)+(b[i]-b0)*(b[i]-b0);
        	e[i][0]=e[0][i];
		}
	for (i=1;i<=n;i++)
	      {
	      	 for (j=1;j<=n;j++) c[j].x=e[i][j],c[j].y=j;
	      	 sort(c+1,c+n+1,cmp);
	      	 for (j=1;j<=n;j++)
	      	    if ((c[j].y)!=i)
	      	     {
	      	     edge[i][0]++;
	      	     edge[i][edge[i][0]]=c[j].y;
	      	     }
		  }
	for (i=1;i<=n;i++)
	   for (j=1;j<=n;j++)
	      g[i][j]=e[i][j]+e[i][0]+e[j][0];
	final=(1<<n)-1;
    for (i=1;i<=(1<<n)-1;i++) f[i]=1000000000;
    f[0]=0;
    ans=1000000000000;
    if ((n % 2)==0)
        { 
        sc(0);
        ans=f[(1<<n)-1];
           i=final;
           while (i>0)
               {
               	if (path_k[i]==1)
               	    {
               	    	w++;u[w]=0;
               	    	w++;u[w]=path_x[i];
               	    	w++;u[w]=path_y[i];
					   }
				else
				    {
				    	w++;u[w]=0;
				    	w++;u[w]=path_x[i];
				    	w++;u[w]=0;
				    	w++;u[w]=path_y[i];
					}
               	i=path[i];
			   }
		cout<<ans<<endl;
		cout<<0<<" ";
		for (i=w;i>=1;i--) cout<<u[i]<<" ";
		cout<<endl;
		}
	else
	   {
       for (i=1;i<=n;i++)
          {
          	for (j=1;j<=(1<<n)-1;j++) f[j]=1000000000; 
          	f[1<<(i-1)]=0;
          	  sc(1<<(i-1));
          	  x=final;
          	  if (f[x]+e[i][0]*2<ans) 
				   {
				   kkk=i;ans=f[x]+e[i][0]*2;
			       }
	      }
	    for (j=1;j<=(1<<n)-1;j++) f[j]=1000000000; 
          	f[1<<(kkk-1)]=0;
        for (i=1;i<=(1<<n)-1;i++) path_x[i]=0,path_y[i]=0,path_k[i]=0,path[i]=0;
        sc(1<<(kkk-1));
	    i=final;
    cout<<ans<<endl;
    cout<<0<<" "<<kkk<<" ";
           while (i!=(1<<(kkk-1)))
               {
               	if (path_k[i]==1)
               	    {
               	    	w++;u[w]=0;
               	    	w++;u[w]=path_x[i];
               	    	w++;u[w]=path_y[i];
					   }
				else
				    {
				    	w++;u[w]=0;
				    	w++;u[w]=path_x[i];
				    	w++;u[w]=0;
				    	w++;u[w]=path_y[i];
					}
               	i=path[i];
			   }
		cout<<0<<" ";
		for (i=w;i>=1;i--) cout<<u[i]<<" ";
		cout<<endl;
       }
    return 0;
}