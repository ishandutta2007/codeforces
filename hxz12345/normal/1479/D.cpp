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
	long long l,r,a,b,tag,id;
} Q[1001010];
int j,Answer[1001010],x,y,l,r,G,curL,curR,L,R,n,m,B,i,uB,used[1001010],fre[1001010],P[1001001],col[1001010],cnt,id,a[1001010],b[1001010],d[1001010],st[1001010],ed[1001010],tag[1001010],dep[1001010],Le[1001010],Ri[1001010],be[1001010],bel[1001010];
int Fa[1001010][22];
void add(int x,int y){cnt++;a[cnt]=y;b[cnt]=d[x];d[x]=cnt;}
void sc(int x,int fa){
    st[x]=++id;tag[id]=x;Fa[x][0]=fa;
    for (int i=1;i<=20;i++) Fa[x][i]=Fa[Fa[x][i-1]][i-1];
	for (int i=d[x];i;i=b[i])
	     if (a[i]!=fa) dep[a[i]]=dep[x]+1,sc(a[i],x);
	ed[x]=++id;tag[id]=x;
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
	    if (dep[Fa[x][i]]>=dep[y]) x=Fa[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
	    if (Fa[x][i]!=Fa[y][i]) x=Fa[x][i],y=Fa[y][i];
	    return Fa[x][0];
}
bool cmp(node a,node b){
	if (bel[a.l]==bel[b.l]) {
		if (bel[a.l]&1) return a.r<b.r;return a.r>b.r;
	}
	return a.l<b.l;
}
void ins(int x){
	fre[col[x]]++;
	if (fre[col[x]]&1) P[be[col[x]]]++;
	else P[be[col[x]]]--;
}
void del(int x){
	fre[col[x]]--;
	if (fre[col[x]]&1) P[be[col[x]]]++;
	else P[be[col[x]]]--;
}
void INS(int x){
	if (used[tag[x]]==0) {used[tag[x]]++;ins(tag[x]);}
	else used[tag[x]]++,del(tag[x]);
}
void DEL(int x){
	if (used[tag[x]]==1) used[tag[x]]--,del(tag[x]);
	else if (used[tag[x]]==2) used[tag[x]]--,ins(tag[x]); 
}
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("mycode.out","w",stdout);
  n=read();m=read();B=sqrt(2*n);dep[1]=1;
  for (i=1;i<=2*n;i++) bel[i]=(i-1)/B+1;
  uB=sqrt(n);
  for (i=1;i<=n;i++) be[i]=(i-1)/uB+1;
  for (i=1;i<=n;i++){
  	Ri[be[i]]=i;
  	if (Le[be[i]]==0) Le[be[i]]=i;
    }
  for (i=1;i<=n;i++) col[i]=read();
  for (i=1;i<n;i++){
  	x=read();y=read();add(x,y);add(y,x);
  }
  sc(1,0);
  for (i=1;i<=m;i++){
  	l=read();r=read();G=lca(l,r);Q[i].a=read(),Q[i].b=read();
  	if (G==l) Q[i].l=st[l],Q[i].r=st[r],Q[i].tag=0,Q[i].id=i;
  	else if (G==r) Q[i].l=st[r],Q[i].r=st[l],Q[i].tag=0,Q[i].id=i;
  	else{
  		if (st[l]>st[r]) swap(l,r);
  		Q[i].l=ed[l];Q[i].r=st[r];Q[i].tag=G;Q[i].id=i;
	  }
  }sort(Q+1,Q+m+1,cmp);
  curL=1;curR=0;
  for (i=1;i<=m;i++){
  	   L=Q[i].l;R=Q[i].r;
  	   while (curL>L) curL--,INS(curL);
  	   while (curR<R) curR++,INS(curR);
  	   while (curL<L) DEL(curL),curL++;
  	   while (curR>R) DEL(curR),curR--;
  	   if (Q[i].tag) ins(Q[i].tag);
       if (be[Q[i].a]==be[Q[i].b]){
       	if (Answer[Q[i].id]==0)
       	for (j=Q[i].a;j<=Q[i].b;j++)
       	    if (fre[j]&1) {
       	    	Answer[Q[i].id]=j;break;
       	    }
	   }else{
	   	   for (j=Q[i].a;j<=Ri[be[Q[i].a]];j++)if (fre[j]&1) {Answer[Q[i].id]=j;break;}
	   	   if (Answer[Q[i].id]==0) for (j=Le[be[Q[i].b]];j<=Q[i].b;j++)if (fre[j]&1) {Answer[Q[i].id]=j;break;}
	   	   if (Answer[Q[i].id]==0){
	   	   	   for (j=be[Q[i].a]+1;j<=be[Q[i].b]-1;j++) if (P[j]) break;
	   	   	   if ((j>be[Q[i].a])&&(j<be[Q[i].b])){
	   	   	   	   L=Le[j];R=Ri[j];
	   	   	   	   for (j=L;j<=R;j++)if (fre[j]&1) {Answer[Q[i].id]=j;break;}
			  }
	   }
	}	
	   if (Q[i].tag) del(Q[i].tag);
  }
  for (i=1;i<=m;i++)
      if (Answer[i]==0) puts("-1");
      else printf("%d\n",Answer[i]);
  return 0;
}