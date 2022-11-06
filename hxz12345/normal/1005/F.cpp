#include<bits/stdc++.h>
using namespace std;
struct hxz{
	int x,y;
};
hxz h[2000000];
long long f[2000000],e1[2000000],e2[2000000],e3[2000000],father2[2000000],father1[2000000],a[2000000],b[2000000],c[2000000],d[2000000];
bool e[2000000];
bool u[2000000];
int K,now[2000000],rit[2000000],uu[2000000],a1[2000000],b1[2000000],d1[2000000];
priority_queue< pair<long long ,int> , vector< pair<long long ,int> > ,greater< pair<long long ,int> > > q;
long long cnt1,num[2000000],ans,j,t,w,x,y,z,cnt,sum,n,m,k,i;
bool cmp(hxz a,hxz b)
{
	return (a.x<b.x);
}
void sc(int x)
{
	if (e[father2[x]]) return;
	e[father2[x]]=true;
	sc(father1[x]);
}
void add(int x,int y,int z)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];c[cnt]=z;d[x]=cnt;
}
void add1(int x,int y)
{
	cnt1++;a1[cnt1]=y;b1[cnt1]=d1[x];d1[x]=cnt1;
}
void sc(int x,int fa)
{
	f[x]=1;
	for (int i=d[x];i;i=b[i])
	    if (a[i]!=fa)
	        {
	        	sc(a[i],x);
	        	h[c[i]].x=f[a[i]];h[c[i]].y=c[i];
	        	f[x]+=f[a[i]];
			}
}
int main()
{
	cin>>n>>m>>K;
	for (i=1;i<=m;i++)
	     {
	     	cin>>x>>y;z=1;
	     	e1[i]=x;e2[i]=y;e3[i]=z;
	     	add(x,y,z);add(y,x,z);
		 }
	for (i=1;i<=n;i++) f[i]=100000000000000000;
	q.push(make_pair(0,1));f[1]=0;
	while (!(q.empty()))
	     {
	     	x=q.top().second;q.pop();
	     	if (u[x]) continue;u[x]=true;
	     	for (i=d[x];i;i=b[i])
	     	    if (f[a[i]]>f[x]+c[i])
	     	        {
	     	        	f[a[i]]=f[x]+c[i];
	     	        	father1[a[i]]=x;father2[a[i]]=(i-1)/2+1;
	     	        	q.push(make_pair(f[a[i]],a[i]));
					 }
		 }
	ans=1;
	for (i=2;i<=n;i++)
	     {
	     	j=i;
	     	while (j!=1)
	     	    {
	     	    	if (e[father2[j]]) break;
	     	    	e[father2[j]]=true;
	     	    	j=father1[j];
				 }
		 }
	
	w=1;
	for (i=1;i<=m;i++)
	    {
	    	num[i]=1;
	    if (e[i])
	        {
	        	uu[i]=1;
	        	if (f[e1[i]]<f[e2[i]])
	        	     {
	        	     	sum=1;rit[i]=i;
	        	     	for (j=d[e2[i]];j;j=b[j])
	        	     	      if ((f[a[j]]==f[e1[i]])&(e[(j-1)/2+1]==false))
	        	     	          {
	        	     	          	num[i]++;
	        	     	          	add1(e2[i],(j-1)/2+1);sum++;
								   }
						now[i]=d1[e2[i]];
						if (ans<=K) ans=ans*sum;
					 }
				else
				    {
				    	sum=1;rit[i]=i;
	        	     	for (j=d[e1[i]];j;j=b[j])
	        	     	      if ((f[a[j]]==f[e2[i]])&(e[(j-1)/2+1]==false))
	        	     	          {
	        	     	          	num[i]++;
	        	     	          	add1(e1[i],(j-1)/2+1);sum++;
								   }
					    now[i]=d1[e1[i]];
						if (ans<=K)
						   ans=ans*sum;
						
					}
			}
	    }
	if (K>ans) K=ans;
	printf("%d\n",K);
	for (;K;K--)
	     {
	     	for (i=1;i<=m;i++) printf("%d",uu[i]);
	     	printf("\n");
	     	bool flag;
	     	i=m;flag=false;
	     	while (1)
	     	    {
	     	    	if (flag) break;
	     	    	if (e[i]==false) 
	     	    	    {
	     	    	    	i--;continue;
						 }
	     	    	if (i<=0) break;
	     	    	if (f[e1[i]]<f[e2[i]])
	     	    	    {
	     	    	    	x=a1[now[i]];
	     	    	    	if (x==0)
	     	    	    	    {
	     	    	    	    	uu[rit[i]]=0;uu[i]=1;
	     	    	    	    	rit[i]=i;now[i]=d1[e2[i]];i--;
								 }
							else
							    {
							    	uu[rit[i]]=0;uu[x]=1;
							    	rit[i]=x;
							    	now[i]=b1[now[i]];flag=true;break;
								}
						 }
					else
					   {
					   	x=a1[now[i]];
	     	    	    	if (x==0)
	     	    	    	    {
	     	    	    	    	uu[rit[i]]=0;uu[i]=1;
	     	    	    	    	rit[i]=i;now[i]=d1[e1[i]];i--;
								 }
							else
							    {
							    	uu[rit[i]]=0;uu[x]=1;
							    	rit[i]=x;
							    	now[i]=b1[now[i]];flag=true;break;
								}
					   }
				 }
		 }
	return 0;
}