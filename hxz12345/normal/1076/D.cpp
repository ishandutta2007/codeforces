#include<bits/stdc++.h>
using namespace std;
struct hxz{
	int x,y;
};
hxz h[2000000];
long long f2[8000000],f[2000000],e1[2000000],e2[2000000],e3[2000000],father2[2000000],father1[2000000],a[2000000],b[2000000],c[2000000],d[2000000];
bool e[2000000];
bool u[2000000];
priority_queue< pair<long long ,int> , vector< pair<long long ,int> > ,greater< pair<long long ,int> > > q;
long long j,t,w,x,y,z,cnt,sum,n,m,k,i;
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
void add1(int x,int y,int z)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];c[cnt]=z;d[x]=cnt;
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
	cin>>n>>m>>k;
	for (i=1;i<=m;i++)
	     {
	     	cin>>x>>y>>z;
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
	for (i=1;i<=m;i++)
	    if (e[i]==false)
	        	sum++;
	if (sum>=m-k)
	     {
	     	cout<<(m-sum)<<endl;
	     	for (i=1;i<=m;i++)
	     	   if (e[i])
	     	       cout<<i<<" ";
	     	return 0;
		 }
	cnt=0;
	for (i=1;i<=n;i++) d[i]=0;
	for (i=1;i<=m;i++)
	    if (e[i])
	       {
	       	add1(e1[i],e2[i],i);add1(e2[i],e1[i],i);
		   }
	for (i=1;i<=n;i++) f[i]=0;
	sc(1,0);
	sort(h+1,h+m+1,cmp);
	cout<<k<<endl;
	for (i=1;i<=m;i++)
	    if (e[h[i].y])
	         {
	         	sum++;
	         	if (sum==m-k) break;
			 }
	for (i=i+1;i<=m;i++)
	    if (e[h[i].y])
	        cout<<h[i].y<<" ";
	return 0;
}