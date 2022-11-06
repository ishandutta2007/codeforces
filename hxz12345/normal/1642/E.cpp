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
	int x,y;
} A[1001010],B[1001010];
vector<int> V[1001010];
bool exist[1001010];
int j,i,n,Q,cas,w,l1,r1,GG,pt,l,r,mid,C[1001010],G,Gq[1001010],F[1001010],Gv[1001010],L[1001010],R[1001010],X[1001010],opt[1001010],J[1001010],tree[1001010],tag[1001010],tree1[1001010];
void pushdown(int x){
	tree[x*2]=tag[x];tree[x*2+1]=tag[x];tag[x*2]=tag[x];tag[x*2+1]=tag[x];
	tag[x]=0;
}
void pushup(int x){
	tree1[x]=max(tree1[x*2],tree1[x*2+1]);
}
void modify(int x,int l,int r,int tl,int tr){
	if ((l>=tl)&&(r<=tr)){
		tree[x]=i;tag[x]=i;return;
	}
	if (tag[x]>0) pushdown(x);
	int mid=(l+r)/2;
	if (tl<=mid) modify(x*2,l,mid,tl,tr);
	if (tr>mid) modify(x*2+1,mid+1,r,tl,tr);
}
void modify1(int x,int l,int r,int tl,int tr,int val){
	if ((l>=tl)&&(r<=tr)){
	tree1[x]=val;return ;
	}
	int mid=(l+r)/2;
	if (tl<=mid) modify1(x*2,l,mid,tl,tr,val);
	if (tr>mid) modify1(x*2+1,mid+1,r,tl,tr,val);
	pushup(x);
}
int find(int x,int l,int r,int tl,int tr){
	if ((l>=tl)&&(r<=tr)) return tree1[x];
	int mid=(l+r)/2;int ans=0;
	if (tl<=mid) ans=max(ans,find(x*2,l,mid,tl,tr));
	if (tr>mid) ans=max(ans,find(x*2+1,mid+1,r,tl,tr));
	pushup(x);
	return ans;
}
int query(int x,int l,int r,int tl,int tr){
	if ((l>=tl)&&(r<=tr)) return tree[x];
	if (tag[x]>0) pushdown(x);
	int mid=(l+r)/2;
	if (tl<=mid) return query(x*2,l,mid,tl,tr);
	if (tr>mid) return query(x*2+1,mid+1,r,tl,tr);
}
int main()
{
	n=read();Q=read();
	for (cas=1;cas<=Q;cas++){
		opt[cas]=read();
		if (opt[cas]==1){
			J[cas]=read();
		}else 
		    {
			L[cas]=read(),R[cas]=read(),X[cas]=read();
			if (X[cas]==0) tag[L[cas]]++,tag[R[cas]+1]--,A[++w].x=L[cas],A[w].y=R[cas];
			else B[++G].x=L[cas],B[G].y=R[cas];
		    }
	}
	for (i=1;i<=n;i++) tag[i]=tag[i-1]+tag[i];
	
	for (i=1;i<=n;i++) Gq[i]=-1;
	for (i=1;i<=n;i++)
	    if (tag[i]>0) exist[i]=true,Gq[i]=0;
	for (i=1;i<=n;i++) tag[i]=0;
	for (i=1;i<=n;i++) F[i]=F[i-1]+exist[i];
	for (i=w;i>=1;i--)
	     modify(1,1,n,A[i].x,A[i].y);
	for (i=1;i<=n;i++) C[i]=query(1,1,n,i,i);
	for (i=1;i<=n;i++) if (C[i]>0) modify1(1,1,n,i,i,C[i]);
	for (i=1;i<=G;i++)
	    	if (F[B[i].y]-F[B[i].x-1]==B[i].y-B[i].x) 
	    	     {
	    	   V[find(1,1,n,B[i].x,B[i].y)].push_back(i);
	    	    Gv[i]=find(1,1,n,B[i].x,B[i].y);
	    	   }
	for (cas=1;cas<=Q;cas++){
		if (opt[cas]==1){
			if (Gq[J[cas]]==-1) puts("N/A");
			if (Gq[J[cas]]==0) 
			    {
				if (C[J[cas]]<=l1) puts("NO");
				else puts("N/A");
			}
			if (Gq[J[cas]]==1) puts("YES");
		}else 
		    {
		    	if (X[cas]==0) 
				    {
				    	
					l1++;
					for (j=0;j<V[l1].size();j++)
					    if (V[l1][j]<=r1){
					    	GG=V[l1][j];pt=B[GG].x;l=B[GG].x;r=B[GG].y;
					    	while (l<=r){
					    		mid=(l+r)/2;
					    		if (F[mid]-F[l-1]!=mid-l+1){
					    			pt=mid;r=mid-1;
								}else l=mid+1;
							    }
							Gq[pt]=1;
						}
						}
		    	if (X[cas]==1) r1++;
		    	if (L[cas]==R[cas]) Gq[L[cas]]=X[cas];
		    	if ((Gv[r1]<=l1)&&(Gv[r1]!=0))
		    	      {
		    	      	GG=r1;pt=B[GG].x;l=B[GG].x;r=B[GG].y;
					    	while (l<=r){
					    		mid=(l+r)/2;
					    		if (F[mid]-F[l-1]!=mid-l+1){
					    			pt=mid;r=mid-1;
								}else l=mid+1;
							    }
							Gq[pt]=1;
							}

				}
		    }
    return 0;
}