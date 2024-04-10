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
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	long long ans=gcd(y,x % y);return ans;
}
//build1:find depth,father,size,height_son 
//build2:find height_son's top and height_son's id
struct node{
	long long siz,dep;
} E[810100];
map<long long,long long> F;
long long u,now,L,R,tot0,tot1,tag[1001010],tree[3][1010100],suf[3][1010100],pre[3][1010100],pos[1001010],treeu,lft,rit,val,opt,VAL[401010],c[501010],j,n,i,x,Testing,y,cnt,up,G,a[401010],H[401010],Val[401010],b[401010],d[401010],dfn[401010],id;
bool exist[2001010];
long long K,ans,z;
void add(int x,int y,int z)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];c[cnt]=z;d[x]=cnt;
}
void build1(int x,int fa)
{
	int j;
	id++;dfn[x]=id;
	E[x].siz=1;
	for (int i=d[x];i;i=b[i])
	   if (a[i]!=fa)
	     {
	     	E[a[i]].dep=E[x].dep+1;
			build1(a[i],x);E[x].siz+=E[a[i]].siz; 
		 }
}
void modify(int sta,int x,long long val)
{
	for (;x<=n;x+=x&-x) tree[sta][x]+=val;
}
long long query(int sta,long long x)
{
	long long ans=0;
	for (;x;x-=x&-x) ans+=tree[sta][x];
	return ans;
}
int main()
{
//	freopen("testdata.in","r",stdin);
    n=read();Testing=read();
    for (i=1;i<=n;i++) VAL[i]=read();
    for (i=1;i<n;i++)
        {
        	x=read();y=read();
        	add(x,y,z);add(y,x,z);
		}
	E[1].dep=1;build1(1,0);
	for (i=1;i<=n;i++) H[dfn[i]]=i;
	
	for (i=1;i<=n;i++)
	   if (E[H[i]].dep % 2==0)
	       {
	       	tot0++;pos[i]=tot0;pre[0][i]=pos[i];pre[1][i]=pre[1][i-1];tag[i]=1;
		   }
	else
	     {
	     	tot1++;pos[i]=tot1;pre[1][i]=pos[i];pre[0][i]=pre[0][i-1];tag[i]=2;
		 }
	suf[0][n+1]=suf[1][n+1]=n+1;
	for (i=n;i>=1;i--)
	    if (tag[i]==1)
	        {
	        	suf[0][i]=pos[i];suf[1][i]=suf[1][i+1];
			}
	else suf[1][i]=pos[i],suf[0][i]=suf[0][i+1];
	for (;Testing;Testing--)
	    {
	    	   opt=read();
	    	   if (opt==1)
	    	       {
	    	       	 u=read();val=read();
	    	       	 lft=dfn[u];rit=dfn[u]+E[u].siz-1;
	    	       	 now=tag[lft]-1;
	    	       	 L=pos[lft];R=pre[now][rit];
	    	       	// cout<<"lft"<<"--->"<<L<<" "<<R<<endl;
	    	       	 modify(now,L,val);modify(now,R+1,-val);
	    	       	 L=suf[now^1][lft];R=pre[now^1][rit];
	    	       	 //cout<<L<<" "<<R<<endl;
	    	       	 if ((L<=R))
	    	       	     modify(now^1,L,-val),modify(now^1,R+1,val);
	    	       	//cout<<query(E[4].dep % 2,pos[dfn[4]])<<"fuck\n";
				   }
				else
				   {
				   	u=read();
				   	printf("%lld\n",VAL[u]+query(E[u].dep % 2,pos[dfn[u]]));
				   }
		}
 return 0;
}