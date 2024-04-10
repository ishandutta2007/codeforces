#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long pow(long long x,long long y,long long p)
{
    long long ans=1;
    for (;y;y>>=1,x=x*x % p)
        if (y&1) ans=ans*x % p;
    return ans;
}
bool exist[1001010],flag;
int ot,gg[1000101],ggu[1000101],dep[1001010],f1[1001010],j,now,fa[100101][21],g[1010][1010],n,i,lg[1001010],x,y,deg[1001010],t,w,a[1001010];
vector<int> edge[100101];
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=lg[n];i>=0;i--)
	     if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    if (x==y) return x;
	for (int i=lg[n];i>=0;i--)
	    if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0]; 
}
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
    n=read();
    for (i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    for (i=1;i<n;i++)
         {
         	x=read();y=read();
         	edge[x].push_back(y);edge[y].push_back(x);deg[x]++;deg[y]++;
		 }
	for (i=1;i<=n;i++)
	   if (deg[i]==1)
	       {
	       	w++;a[w]=i;
		   }
	for (i=1;i<=w/2;i++)
	    {
	    	cout<<"? "<<a[i*2-1]<<" "<<a[i*2]<<endl;
	        cin>>x;g[a[i*2-1]][a[i*2]]=x;
	        if ((x==a[i*2-1]))
	             {
	             	cout<<"! "<<a[i*2-1]<<endl;return 0;
				 }
			if (x==a[i*2])
			     {
			     	cout<<"! "<<a[i*2]<<endl;return 0;
				 }
			exist[x]=true;
	    	cout.flush();
		}
	if (w % 2==1) 
	    {
		cout<<"? "<<a[w]<<" "<<a[1]<<endl;
		
        cin>>x;g[a[w]][a[1]]=x;exist[x]=true;
          if ((x==a[w]))
	             {
	             	cout<<"! "<<a[w]<<endl;return 0;
				 }
			if (x==a[1])
			     {
			     	cout<<"! "<<a[1]<<endl;return 0;
				 }
		cout.flush();
        }
	for (i=1;i<=n;i++)
	    for (j=1;j<=n;j++)
		    if ((i!=j)&&(g[i][j]==false)&&(g[j][i]==false))
			    if ((w+1)/2+(ot+1)<=n/2)
				       {
                        cout<<"? "<<i<<" "<<j<<endl;
		ot++;gg[ot]=i;ggu[ot]=j;
        cin>>x;g[i][j]=x;exist[x]=true;			       	
							 }      
    for (now=1;now<=n;now++)
       if (exist[now])
            {
            	exist[now]=false;
            	for (i=1;i<=n;i++) dep[i]=1e9;
            	for (i=1;i<=n;i++)
            	    for (j=0;j<=lg[n];j++)
            	        fa[i][j]=0;
            	dep[now]=1;t=1;w=1;f1[1]=now;
            	while (t<=w)
            	     {
            	     	for (i=0;i<edge[f1[t]].size();i++) 
            	     	     {
            	     	     	y=edge[f1[t]][i];
            	     	     	if (dep[y]>dep[f1[t]]+1)
            	     	     	     {
            	     	     	     	dep[y]=dep[f1[t]]+1;
            	     	     	     	fa[y][0]=f1[t];
            	     	     	     	for (j=1;j<=lg[n];j++)
            	     	     	     	    fa[y][j]=fa[fa[y][j-1]][j-1];
									   w++;f1[w]=y;
									   }
							  }
            	     	t++;
				    }
			flag=false;
			for (i=1;i<=w/2;i++)
			    if (lca(a[i*2-1],a[i*2])!=g[a[i*2-1]][a[i*2]])
					flag=true;
			if (w % 2==1)
			    if (lca(a[w],a[1])!=g[a[w]][a[1]])
			        flag=true;
			for (i=1;i<=ot;i++)
			    if (lca(gg[i],ggu[i])!=g[gg[i]][ggu[i]])
			         flag=true;
			if (flag==false)
			     { 
			     cout<<"! "<<now<<endl;
			     return 0;
				 }
			}
    return 0;
}