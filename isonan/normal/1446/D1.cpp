#include <cstdio>
#include <algorithm>

int n,a[200001],cnt[101][200001],pre[200001],last[200001];
int f[200001];
struct info{
	int m1,m2,v1,v2;
};
info get(int l,int r){
	int m1=0,m2=0,v1=-1,v2=-1;
	for(int i=1;i<=100;i++){
		int v=cnt[i][r]-cnt[i][l-1];
		if(v1<v){
			v2=v1,m2=m1;
			v1=v,m1=i;
		}
		else if(v2<v){
			v2=v,m2=i;
		}
	}
	return (info){m1,m2,v1,v2};
}
int slice(int i,int l,int r){
	return cnt[i][r]-cnt[i][l-1];
}
int se[2000001],mn[2000001],lazy[2000001];
void pushdown(int x,int y){
	se[x]+=y;
	lazy[x]+=y;
}
void spread(int x){
	if(lazy[x]){
		pushdown(x<<1,lazy[x]);
		pushdown(x<<1|1,lazy[x]);
		lazy[x]=0;
	}
}
int sum[200001];
void build(int root,int l,int r){
	lazy[root]=0;
	if(l==r){
		se[root]=-sum[l-1];
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	se[root]=std::min(se[root<<1],se[root<<1|1]);
}
void update(int root,int l,int r,int el,int er,int x){
//	if(root==1)printf("update %d %d %d\n",el,er,x);
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		pushdown(root,x);
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	se[root]=std::min(se[root<<1],se[root<<1|1]);
}
int get(int root,int l,int r,int s){
//	printf("get %d %d %d\n",l,r,se[root]);
	if(se[root]+s>0)return n+1;
	spread(root);
	if(l==r)return l;
	if(se[root<<1]+s<=0)return get(root<<1,l,(l+r)>>1,s);
	else return get(root<<1|1,((l+r)>>1)+1,r,s);
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		for(int j=1;j<=100;j++)
			cnt[j][i]=cnt[j][i-1];
		pre[i]=last[a[i]];
		last[a[i]]=i;
		++cnt[a[i]][i]; 
	}
	info now=get(1,n);
	if(now.v1==now.v2){
		printf("%d",n);
		return 0;
	}
	int mx=now.m1;
	int r=n-1;
	int ans=0;
	for(;r;){
		now=get(1,r);
		if(now.v1==now.v2){
			ans=std::max(ans,r);
			break;
		}
		--r;
	}
	for(int i=1;i<=n;i++)f[i]=n+1;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(a[i]==mx);
	for(int j=1;j<=100;j++){
		if(j==mx)continue;
		build(1,1,n);
		for(int k=1,last=n+1;k<=n;k++){
			if(a[k]==j){
				update(1,1,n,1,k,-1);
			}
			f[k]=std::min(f[k],get(1,1,n,sum[k]));
		}
	}
	for(int i=r+1;i<=n;i++)ans=std::max(ans,i-f[i]+1);
	printf("%d\n",ans);
}