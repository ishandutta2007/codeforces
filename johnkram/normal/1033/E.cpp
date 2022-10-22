#include<bits/stdc++.h>
using namespace std;
int n,m,N,A,B,i,j,s,h[605],ne[1205],p[1205],f[605],d[605];
bool v[605];
queue<int> q;
vector<int> a,b,c;
string E,D;
map<string,int> M;
int ask(int x,int l,int r)
{
	int s,i;
	D=E;
	for(i=l;i<=r;i++)D[a[i]]='1';
	D[x]='1';
	if(M.count(D))s=M[D];
	{
	    printf("? %d\n",r-l+2);
	    for(i=l;i<=r;i++)printf("%d ",a[i]);
	    printf("%d\n",x);
	    fflush(stdout);
	    scanf("%d",&s);
	    M[D]=s;
	}
	if(l==r)i=0;
	else
	{
	    D=E;
	    for(i=l;i<=r;i++)D[a[i]]='1';
	    if(M.count(D))i=M[D];
	    else
	    {
		    printf("? %d\n",r-l+1);
	    	for(i=l;i<=r;i++)printf("%d%c",a[i],i==r?'\n':' ');
	    	fflush(stdout);
	    	scanf("%d",&i);
	    	M[D]=i;
	    }
	}
	return s-i;
}
void work(int x,int l,int r)
{
	if(l==r)
	{
		p[++m]=a[l];
		ne[m]=h[x];
		h[x]=m;
		p[++m]=x;
		ne[m]=h[a[l]];
		h[a[l]]=m;
		q.push(a[l]);
		a.erase(a.begin()+l);
		A--;
		return;
	}
	int mid=l+r>>1;
	if(ask(x,l,mid))work(x,l,mid);
	else work(x,mid+1,r);
}
void dfs(int x)
{
	for(int i=h[x];i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=x;
		d[p[i]]=d[x]+1;
		v[p[i]]=!v[x];
		dfs(p[i]);
	}
}
bool work()
{
	int i,j,k;
    D=E;
    for(i=0;i<A;i++)D[a[i]]='1';
    if(M.count(D))i=M[D];
    else
    {
	    printf("? %d\n",A);
    	for(i=0;i+1<A;i++)printf("%d ",a[i]);
    	printf("%d\n",a[i]);
    	fflush(stdout);
    	scanf("%d",&i);
    	M[D]=i;
    }
	if(!i)return 1;
	for(i=A-1;i;i--)if(ask(a[i],0,i-1))break;
	for(j=0;j<i;j++)if(ask(a[i],j,j))break;
	i=a[i];
	j=a[j];
	if(d[i]>d[j])swap(i,j);
	b.clear();
	c.clear();
	for(;d[j]!=d[i];j=f[j])b.push_back(j);
	for(;j!=i;j=f[j],i=f[i])
	{
		b.push_back(j);
		c.push_back(i);
	}
	reverse(c.begin(),c.end());
	b.push_back(i);
	for(i=0;i<c.size();i++)b.push_back(c[i]);
	B=b.size();
	printf("N %d\n",B);
	for(i=0;i+1<B;i++)printf("%d ",b[i]);
	printf("%d\n",b[i]);
	fflush(stdout);
	return 0;
}
int main()
{
	cin>>n;
	for(i=0;i<=n;i++)E+='0';
	if(n==1)
	{
		puts("Y 0");
		fflush(stdout);
		return 0;
	}
	q.push(1);
	v[1]=1;
	for(i=2;i<=n;i++)a.push_back(i);
	for(A=a.size();A&&!q.empty();)
	{
		i=q.front();
		q.pop();
		s=ask(i,0,A-1);
		if(!s)continue;
		while(s--)work(i,0,A-1);
	}
	v[1]=0;
	dfs(1);
	a.clear();
	for(i=1;i<=n;i++)if(v[i])a.push_back(i);
	A=a.size();
	if(!work())return 0;
	a.clear();
	for(i=1;i<=n;i++)if(!v[i])a.push_back(i);
	A=a.size();
	if(!work())return 0;
	printf("Y %d\n",A);
	for(i=0;i+1<A;i++)printf("%d ",a[i]);
	printf("%d\n",a[i]);
	fflush(stdout);
	return 0;
}