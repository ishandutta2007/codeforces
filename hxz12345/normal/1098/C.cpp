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
long long up,U,ww,aa[1001010],fre[1001010],ls[1001010],nw,id,deg[1001010],gg,j,dfn[1001010],di,fat[1001010],n,i,idd,dfnn[1001010],K,l,r,mid,ans,down,bb,dif,now,ed[1001010],sum,dep[1001010],e[1001010];
vector<int> edge[1001010];
bool exist[1001010];
void sc(int x,int fa)
{
	dep[x]=1;
	for (int i=0;i<edge[x].size();i++)
	    {
	    	int y=edge[x][i];
	    	if (dep[y]==0)
	    	    {
	    	    	sc(y,x);dep[x]+=dep[y];
				}
		}
}
long long calc(long long mid)
{
	for (i=1;i<=n;i++) edge[i].clear(),dep[i]=0;
    for (i=1;i<=n;i++) fre[i]=0;
    int nw=1;
    for (i=2;i<=n;i++)
         {
         	edge[nw].push_back(i);
         	fre[nw]++;
         	if (fre[nw]==mid) nw++;
		 }
	sc(1,0);
	long long ans=0;
	for (i=1;i<=n;i++) ans+=dep[i];
	return ans;
}
void sc_build(int x,int fa)
{
id++;dfnn[id]=x;
for (int i=0;i<edge[x].size();i++)
	if (edge[x][i]!=fa)
	 {
     	dep[edge[x][i]]=dep[x]+1;
     sc_build(edge[x][i],x);
     }
}
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
    n=read();K=read();
    if ((K<2*n-1)||(K>n*(n+1)/2))
          {
          	puts("No");return 0;
		  }
	puts("Yes");
    l=1;r=n-1;
    while (l<=r)
         { 
         mid=(l+r)/2;
         if (calc(mid)<=K)
              {
              ans=mid;r=mid-1;
		      }
		  else l=mid+1;
		 }
	down=calc(ans);dif=K-down;bb=1;
//	cout<<dif<<endl;
	for (now=0;now<n;now+=bb,bb*=ans)
	    sum++,ed[sum]=now+1,exist[now+1]=true;
	     //cout<<"fuck"<<sum<<endl;
	for (i=1;i<=n;i++) edge[i].clear();
	for (i=1;i<=n;i++) fre[i]=0,dep[i]=0;
	dep[1]=1;
nw=1;
	for (i=2;i<=n;i++)
	     {
	     	edge[nw].push_back(i);deg[nw]++;deg[i]++;
	     	fat[i]=nw;
	     	fre[nw]++;
	     	if (fre[nw]==ans) nw++;
		 }
	sc_build(1,0);idd=sum;
	for (i=1;i<=n;i++)
	    if (exist[i]==false)
	       {
	       	gg++;up=dfnn[i];for (j=dfnn[i];j;j=fat[j]) up=j;
	       	U=max(U,dep[i]);
	       	if ((gg>1)&&(up==2))
	       	     {
	       	     	ww++;aa[ww]=i;
					}
			 }  
	for (i=U;i>=1;i--)
	     for (j=1;j<=ww;j++)
	         if (dep[aa[j]]==i)
	             {
	             	idd++;dfn[idd]=aa[j];exist[aa[j]]=true;
				 }
		ww=0;
		for (i=1;i<=n;i++)
		   if (exist[i]==false)
	       {
	       	gg++;up=dfnn[i];for (j=dfnn[i];j;j=fat[j]) up=j;
	       	U=max(U,dep[i]);
	       	if ((gg>1)&&(up!=2))
	       	     {
	       	     	ww++;aa[ww]=i;
					}
			 }  
	for (i=U;i>=1;i--)
	     for (j=1;j<=ww;j++)
	         if (dep[aa[j]]==i)
	             {
	             	idd++;dfn[idd]=aa[j];
				 }
    //sum:
    //cout<<fat[2]<<endl;
    if (dif!=0)
        {
    for (i=sum+1;i<=n;i++)
        { 
        now=dfn[i];//cout<<now<<endl;
        if (dif>sum-dep[now]+1)  
             { 
             dif-=(sum-dep[now]+1);
             fat[now]=ed[sum];
             sum++;ed[sum]=now;
			 }
		else
		    { 
		    di=dep[now]+dif-1;
		    //cout<<ed[di]<<endl;
		    dif=0;
		    fat[now]=ed[di];break;
			}
		}
    }
    //cout<<"------"<<dif<<"------"<<endl;
for (i=2;i<=n;i++) printf("%d ",fat[i]);
    return 0;
}