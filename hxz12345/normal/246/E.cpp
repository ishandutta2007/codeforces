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
	int col,top,fa,siz,hson,dep;
} E[510100];
set<int> Set[201010];
int col[1001010],up[1001010],Answer[1001010],opt,H[1010100],dfn[1010100],e[1010100],a[1010100],b[1010100],d[1010100],ans;
int len,u,v,cnt,n,m,i,T,x,y,id;
bool exist[1010100];
string lsh[1001010],Strin[100100];
int Testing;
vector<pair<int,int>> Asking[101000];
void add(int x,int y)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void build1(int x,int fa)
{
	id++;dfn[x]=id;
	E[x].siz=1;int mx=0;E[x].hson=0;
	for (int i=d[x];i;i=b[i])
	   if (a[i]!=fa)
	     {
	     	E[a[i]].dep=E[x].dep+1;
            E[a[i]].fa=x;build1(a[i],x);E[x].siz+=E[a[i]].siz; 
			if (E[a[i]].siz>mx) mx=E[a[i]].siz,E[x].hson=a[i];    	
		 }
	if (E[x].hson!=0) exist[E[x].hson]=true;
}
void delet(int x)
{
	//cout<<"-----"<<x<<"-----\n";
	for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++)
	      Set[E[H[i]].dep].clear();
}
void insert(int x,int fa)
{
	for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++)
	      Set[E[H[i]].dep].insert(E[H[i]].col);
}
void sc(int x,int fa)
{
	int i;
	for (i=d[x];i;i=b[i])
	     if (a[i]!=fa)
	         if (a[i]!=E[x].hson)
	            {
	            sc(a[i],x);
	            delet(a[i]);
	            }
	if (E[x].hson!=0)
	    {
	     sc(E[x].hson,x);
	     //cout<<"---"<<x<<"---:"<<Answer[x]<<endl;
    	for (i=d[x];i;i=b[i])
	     if (a[i]!=fa)
	         if (a[i]!=E[x].hson)
	            insert(a[i],x);
	   }
	Set[E[x].dep].insert(E[x].col);
	for (i=0;i<Asking[x].size();i++)
	    Answer[Asking[x][i].second]=Set[E[x].dep+Asking[x][i].first].size();
}
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	char s[1010];
	cin>>n;
	for (i=1;i<=n;i++) 
	    {
	    	cin>>Strin[i]>>x;
	    	lsh[i]=Strin[i];
	    	if (x==0) x=n+1;
	    	add(x,i);
		 } 
	sort(lsh+1,lsh+n+1);len=unique(lsh+1,lsh+n+1)-lsh-1;
	for (i=1;i<=n;i++) E[i].col=lower_bound(lsh+1,lsh+len+1,Strin[i])-lsh;
	E[n+1].dep=1;build1(n+1,0);
	for (i=1;i<=n+1;i++) H[dfn[i]]=i;
	cin>>Testing; 
	for (i=1;i<=Testing;i++)
	   { 
	     cin>>x>>y;
	      Asking[x].push_back(make_pair(y,i));
	   }
	sc(n+1,0);
	for (i=1;i<=Testing;i++) cout<<Answer[i]<<endl;
 return 0;
}