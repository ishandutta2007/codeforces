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
struct Node{
	int a,b;
};
struct node{
	int siz,hson,dep;
} E[4010100];
vector<pair<int,int>> Asking[301010];
int col[1001010],F[6001010],j,Answer[4000101],n,i,x,Testing,y,cnt,up,G,a[2001010],H[2001010],Val[2001010],b[2001010],d[2001010],dfn[2001010],id;
bool AAA[4001010],exist[2001010];
string VA;
void add(int x,int y)
{
	cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;
}
void build1(int x,int fa)
{
	int j;
	id++;dfn[x]=id;
	E[x].siz=1;int mx=0;E[x].hson=0;
	for (int i=d[x];i;i=b[i])
	   if (a[i]!=fa)
	     {
	     	E[a[i]].dep=E[x].dep+1;
			build1(a[i],x);E[x].siz+=E[a[i]].siz; 
			if (E[a[i]].siz>mx) mx=E[a[i]].siz,E[x].hson=a[i];    	
		 }
	if (E[x].hson!=0) exist[E[x].hson]=true;
}
void delet(int x)
{
	for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++) F[col[H[i]]]=0;
}
void ToDoIt(int x,int fa)
{
	int j;
	for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++) 
	     {
	     	if (F[col[H[i]]]!=0) Answer[fa]=max(Answer[fa],F[col[H[i]]]+E[H[i]].dep-E[fa].dep*2);
	     	for (j=0;j<22;j++)
	     	    	if (F[col[H[i]]^(1<<j)]!=0) Answer[fa]=max(Answer[fa],F[col[H[i]]^(1<<j)]+E[H[i]].dep-E[fa].dep*2);
		 } 
}
void insert(int x)
{
	for (int i=dfn[x];i<=dfn[x]+E[x].siz-1;i++) F[col[H[i]]]=max(F[col[H[i]]],E[H[i]].dep);
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
	    Answer[x]=Answer[E[x].hson];
       for (i=d[x];i;i=b[i])
    	    {
	       if (a[i]!=fa)
	         if (a[i]!=E[x].hson)
	            {
	            	ToDoIt(a[i],x);
	            	insert(a[i]);
	            	Answer[x]=max(Answer[x],Answer[a[i]]);
				}
		}
	    if (F[col[x]]!=0) Answer[x]=max(Answer[x],F[col[x]]-E[x].dep);
	    for (i=0;i<22;i++) 
	    if (F[col[x]^(1<<i)]!=0) 
		     Answer[x]=max(Answer[x],F[col[x]^(1<<i)]-E[x].dep);
	   }
	F[col[x]]=max(F[col[x]],E[x].dep);
}
void build_col(int x)
{
	for (int i=d[x];i;i=b[i])
	    col[a[i]]^=col[x],build_col(a[i]);
}
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
    cin>>n;
	for (i=2;i<=n;i++)
        {
        	cin>>x>>VA;col[i]=1<<(VA[0]-'a');
        	add(x,i);
		}
	build_col(1);
     E[1].dep=1;build1(1,0);
	for (i=1;i<=n;i++) H[dfn[i]]=i;
    sc(1,0);
    for (i=1;i<=n;i++) cout<<Answer[i]<<" ";
 return 0;
}