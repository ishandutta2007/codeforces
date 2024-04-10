#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

int orig[100001],n,L,R,head[100001],nxt[200001],b[200001],v[200001],k,lim,mx[100001],size[100001],full,root,l=1,r,mid,ans=-1,Dis[200001];
int MxVal[100001],TemMxVal[100001],ValTop,MxValPos[100001],TemMxValPos[100001];
int tax[100001],stk[100001],top,pos[100001],val[100001],pval[100001];
int q[100001],Top,Head,U,V;
bool vis[100001];
inline void dmax(int &a,int b,int &c,int d){if(a<b)a=b,c=d;}
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void getroot(int x,int f){
	size[x]=1,mx[x]=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]]){
			getroot(b[i],x);
			size[x]+=size[b[i]];
			mx[x]=max(mx[x],size[b[i]]);
		}
	mx[x]=max(mx[x],full-size[x]);
	if(mx[x]<mx[root])root=x;
}
void GetMaxDis(int x,int f,int dis,int &ans){
	ans=max(ans,dis);
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f&&!vis[b[i]])GetMaxDis(b[i],x,dis+1,ans);
}
bool getdis(int x,int f,int dis,int length){
//	printf("%d %d %d %d %d\n",x,f,root,dis,length);
	if(length>=L&&length<=R&&dis>=0){
		U=x;
		V=root;
		return 1;
	}
	size[x]=1;
	if(length<=R)dmax(TemMxVal[length],dis,TemMxValPos[length],x);
	for(int i=head[x];i;i=nxt[i]){
		if(b[i]!=f&&!vis[b[i]]){
//			printf("&&& %d %d %d\n",b[i],v[i],x);
			if(getdis(b[i],x,dis+((v[i]>=mid)?1:-1),length+1))return 1;
			size[x]+=size[b[i]];
		}
	}
	return 0;
}
bool solve(int rt){
	vis[rt]=1;
	top=0;
	for(int i=head[rt];i;i=nxt[i])
		if(!vis[b[i]]){
			stk[++top]=b[i];
			Dis[top]=0;
			val[top]=(v[i]>=mid)?1:-1;
//			printf("|$ %d %d\n",stk[top],val[top]);
			GetMaxDis(b[i],rt,1,Dis[top]);
		}
	for(int i=1;i<=full;++i)tax[i]=0;
	for(int i=1;i<=top;++i)++tax[Dis[i]];
	for(int i=1;i<=full;++i)tax[i]+=tax[i-1];
	for(int i=top;i;--i){
		pos[tax[Dis[i]]]=stk[i];
		pval[tax[Dis[i]]]=val[i];
		--tax[Dis[i]];
	}
//	printf("root:%d\n",rt);
//	for(int i=1;i<=top;++i)printf("%d %d\n",pos[i],pval[i]);
	ValTop=0;
//	for(int j=1;TemMxVal[j]!=-n;++j)printf("%d ",TemMxVal[j]);
//	putchar('\n');
	for(int i=1;i<=top;++i){
		if(getdis(pos[i],rt,pval[i],1))return 1;
//		printf("subtree %d when root is %d , val is %d, ValTop is %d\n",pos[i],rt,pval[i],ValTop);
//		for(int j=1;TemMxVal[j]!=-n;++j)printf("%d ",TemMxVal[j]);putchar('\n');
//		for(int j=1;j<=ValTop;j++)printf("%d ",MxVal[j]);putchar('\n');
		Top=Head=0;
		for(int j=1;j<=ValTop;++j){
			while(Head<Top&&MxVal[q[Top]]<=MxVal[j])--Top;
			q[++Top]=j;
			while(q[Head+1]<j-R+L)++Head;
			if(TemMxVal[R-j]!=-n&&TemMxVal[R-j]+MxVal[q[Head+1]]>=0){
				U=TemMxValPos[R-j];
				V=MxValPos[q[Head+1]];
				return 1;
			}
//			printf("%d %d\n",Head,Top);
		}
		int tem=ValTop;
		while(TemMxVal[tem+1]!=-n)++tem;
		for(int j=tem;j;--j){
			if(R-j>ValTop){
//				printf("!@#$%^ %d %d %d\n",R-j,TemMxVal[j],L-j);
				while(Head<Top&&q[Head+1]<L-j)++Head;
//				printf("%d %d %d %d %d %d\n",TemMxVal[j],j,q[Head+1],MxVal[q[Head+1]],Head,Top);
				if(Head<Top&&TemMxVal[j]+MxVal[q[Head+1]]>=0){
					U=TemMxValPos[j];
					V=MxValPos[q[Head+1]];
					return 1;
				}
//				printf("%d %d %d %d %d %d\n",TemMxVal[j],j,q[Head+1],MxVal[q[Head+1]],Head,Top);
			}
		}
		ValTop=tem;
		for(int j=1;j<=ValTop;++j){
			dmax(MxVal[j],TemMxVal[j],MxValPos[j],TemMxValPos[j]);
			TemMxVal[j]=-n;
		}
	}
	for(int j=1;j<=ValTop;++j)MxVal[j]=-n;
	for(int i=head[rt];i;i=nxt[i])
		if(!vis[b[i]]){
			mx[root=0]=full=size[b[i]];
			getroot(b[i],rt);
			if(solve(root))return 1;
		}
	return 0; 
}
int main(){
	scanf("%d%d%d",&n,&L,&R);
	for(int i=1;i<=n;i++)MxVal[i]=TemMxVal[i]=-n;
	for(int a,b,c,i=1;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		push(a,b,c);
		push(b,a,c);
		orig[i]=c;
	}
	std::sort(orig+1,orig+n);
	r=std::unique(orig+1,orig+n)-orig-1;
//	for(int i=1;i<=r;i++)printf("%d ",orig[i]);putchar('\n');
	for(int i=1;i<=k;i++)v[i]=std::lower_bound(orig+1,orig+r+1,v[i])-orig;
	while(l<=r){
		mid=(l+r)>>1;
		mx[root=0]=full=n;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)MxVal[i]=TemMxVal[i]=-n;
		getroot(1,0);
//		printf("%d\n",mid);
		if(solve(root))l=mid+1;
		else r=mid-1;
	}
	printf("%d %d\n",U,V);
}