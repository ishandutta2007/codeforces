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
struct node{
	int sx,sy,tx,ty,id;
} b[601010],c[601010];
char S[1001010];
int i,j,Q,n,m,Answer[1001010],a[502][502];
bitset<502> f[502][502];
bitset<502> g[502][502];
bitset<502> V;
//f[i][j][k] (i,j) (mid,k)
//g[i][j][k] (mid,k)(i,j),(i,j)(mid,k) 
void solve(int l,int r,int tl,int tr){
	if ((l>r)||(tl>tr)) return ;
	int mid=(l+r)>>1;
	int i,j;
	for (i=1;i<=m;i++) f[mid][i]=g[mid][i]=0;
	for (i=m;i>=1;i--)
	    if (a[mid][i]==1) f[mid][i][i]=1,f[mid][i]|=f[mid][i+1];
	for (i=1;i<=m;i++)
	    if (a[mid][i]==1) g[mid][i][i]=1,g[mid][i]|=g[mid][i-1];
	for (i=mid-1;i>=l;i--)
	   for (j=m;j>=1;j--)
	       if (a[i][j]==1) f[i][j]=f[i+1][j]|f[i][j+1];
	       else f[i][j]=0;
	for (i=mid+1;i<=r;i++)
	   for (j=1;j<=m;j++)
	       if (a[i][j]==1) g[i][j]=g[i-1][j]|g[i][j-1];
	       else g[i][j]=0;
	int L=tl-1,R=tr+1;
	for (i=tl;i<=tr;i++){
		if ((b[i].sx<mid)&&(b[i].tx<mid)) {c[++L]=b[i];continue;}
		if ((b[i].sx>mid)&&(b[i].tx>mid)) {c[--R]=b[i];continue;}
		V=f[b[i].sx][b[i].sy]&g[b[i].tx][b[i].ty];
		if (V.count()>0) Answer[b[i].id]=1; 
	}
	for (i=tl;i<=L;i++) b[i]=c[i];
	for (i=R;i<=tr;i++) b[i]=c[i];
	solve(l,mid,tl,L);solve(mid+1,r,R,tr);
}
int main()
{
	n=read();m=read();
	for (i=1;i<=n;i++){
		scanf("%s",S+1);
		for (j=1;j<=m;j++)
		   if (S[j]=='.') a[i][j]=1;
	}
	Q=read();
	for (i=1;i<=Q;i++) b[i].sx=read(),b[i].sy=read(),b[i].tx=read(),b[i].ty=read(),b[i].id=i;
	solve(1,n,1,Q);
	for (i=1;i<=Q;i++)
	    if (Answer[i]==1) puts("Yes");else puts("No");
	return 0;
}