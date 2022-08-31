#include <cstdio>
#include <vector>

int n,Q,k,a[300001];
int b[300001],l[300001],r[300001];
int q[300001],h,t;
long long se[3000001];
int lazy[3000001],siz[3000001];
void build(int root,int l,int r){
	siz[root]=r-l+1;
	se[root]=0;
	lazy[root]=-1;
	if(l==r)return;
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
}
void pushdown(int x,int y){
	se[x]=1ll*siz[x]*y;
	lazy[x]=y;
}
void spread(int x){
	if(lazy[x]!=-1){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=-1;
	}
}
void update(int root,int l,int r,int el,int er,int y){
	// if(root==1)printf("update %d %d %d\n",el,er,y);
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,y);
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,y);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,y);
	se[root]=se[root<<1]+se[root<<1|1];
}
long long query(int root,int l,int r,int el,int er){
	if(el>r||er<l)return 0ll;
	if(el<=l&&er>=r)return se[root];
	spread(root);
	return query(root<<1,l,(l+r)>>1,el,er)+query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
std::vector<int>que[300001];
int pos[300001],top;
long long ans[300001];
int main(){
	scanf("%d%d%d",&n,&Q,&k);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=n;i;--i){
		while(h<t&&a[q[t]]>a[i])--t;
		q[++t]=i;
		while(h<t&&q[h+1]>=i+k)++h;
		b[i]=a[q[h+1]];
		// printf("%d\n",b[i]);
	}
	for(int i=1;i<=Q;++i){
		scanf("%d%d",l+i,r+i);
		ans[i]=a[l[i]];
		que[l[i]].push_back(i);
	}
	for(int i=0;i<k;++i){
		int s=(i==0)?k:i;
		top=0;
		for(int j=s+1;j+k-1<=n;j+=k)pos[++top]=j;
		if(!top)continue;
		build(1,1,top);
		h=t=0;
		for(int j=top;j;--j){
			while(t&&b[pos[q[t]]]>b[pos[j]])--t;
			update(1,1,top,j,t?q[t]-1:top,b[pos[j]]);
			q[++t]=j;
			int l=1,r=t,mid,p=0;
			while(l<=r){
				mid=(l+r)>>1;
				if(b[pos[q[mid]]]<=a[pos[j]-1])p=mid,l=mid+1;
				else r=mid-1;
			}
			if(!p)p=top+1;
			else p=q[p];
			for(int u:que[pos[j]-1]){
				int R=(::r[u]-::l[u])/k;
				// printf("%d %d %d %d %d\n",u,i,R,p,j);
				ans[u]=1ll*a[::l[u]]*std::min(R+1,p-j+1)+query(1,1,top,p,j+R-1);
			}
		}
	}
	for(int i=1;i<=Q;++i)printf("%lld\n",ans[i]);
}