#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

struct segtree{
	int ord[100001],p[100001];
	int se[1000001];
	void build(int root,int l,int r){
		if(l==r){
			se[root]=0;
			return;
		}
		build(root<<1,l,(l+r)>>1);
		build(root<<1|1,((l+r)>>1)+1,r);
		se[root]=std::max(se[root<<1],se[root<<1|1]);
	}
	void set(int root,int l,int r,int e,int x){
		if(l==r){
			se[root]=x;
			return;
		}
		if((l+r)>>1>=e)set(root<<1,l,(l+r)>>1,e,x);
		else set(root<<1|1,((l+r)>>1)+1,r,e,x);
		se[root]=std::max(se[root<<1],se[root<<1|1]);
	}
	int query(int root,int l,int r,int el,int er){
		if(el>r||er<l)return 0;
		if(el<=l&&er>=r)return se[root];
		return std::max(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
	}
	void get1(int root,int l,int r,int e,int *a,int &top){
		if(se[root]==0)return;
		if(l>=e)return;
		if(l==r){
			a[++top]=ord[l];
			se[root]=0;
			return;
		}
		get1(root<<1,l,(l+r)>>1,e,a,top);
		get1(root<<1|1,((l+r)>>1)+1,r,e,a,top);
		se[root]=std::max(se[root<<1],se[root<<1|1]);
	}
	void get2(int root,int l,int r,int e,int *a,int &top){
		if(se[root]==0)return;
		if(top==e)return;
		if(l==r){
			a[++top]=ord[l];
			se[root]=0;
			return;
		}
		get2(root<<1,l,(l+r)>>1,e,a,top);
		get2(root<<1|1,((l+r)>>1)+1,r,e,a,top);
		se[root]=std::max(se[root<<1],se[root<<1|1]);
	}
}s1,s2;
int n,m;
int que[200001][3],H[100001],f[100001];
std::pair<int,int>v[100001];
int stk[21],top;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&que[i][0],&que[i][1]);
		if(que[i][0]==1)scanf("%d",&que[i][2]),H[que[i][1]]=v[que[i][1]].first=que[i][2]-i;
	}
	for(int i=1;i<=n;++i)v[i].second=-i;
	std::sort(v+1,v+n+1);
	for(int i=1;i<=n;++i)s1.p[-v[i].second]=i,s1.ord[i]=-v[i].second;
	for(int i=1;i<=n;++i)s2.p[i]=s2.ord[i]=i;
	s1.build(1,1,n);
	s2.build(1,1,n);
	for(int i=1;i<=m;++i){
		int opt=que[i][0];
		if(opt==1){
			int x=que[i][1];
			top=0;
			s1.get1(1,1,n,s1.p[x],stk,top);
			for(int i=1;i<=top;++i)s2.set(1,1,n,s2.p[stk[i]],0);
			stk[++top]=x;
			for(int i=top;i;--i){
				f[stk[i]]=s2.query(1,1,n,s2.p[stk[i]],n)+1;
				for(int j=i+1;j<=top;++j)
					if(stk[i]<stk[j])f[stk[i]]=std::max(f[stk[i]],f[stk[j]]+1);
			}
			for(int i=1;i<=top;++i){
				s1.set(1,1,n,s1.p[stk[i]],f[stk[i]]);
				s2.set(1,1,n,s2.p[stk[i]],f[stk[i]]);
			}
		}
		else{
			int x=que[i][1];
			top=0;
			s2.get2(1,1,n,x,stk,top);
			for(int i=1;i<=top;++i)s1.set(1,1,n,s1.p[stk[i]],0);
			--top;
			for(int i=top;i;--i){
				f[stk[i]]=s1.query(1,1,n,s1.p[stk[i]],n)+1;
				for(int j=i+1;j<=top;++j)
					if(H[stk[i]]<H[stk[j]])f[stk[i]]=std::max(f[stk[i]],f[stk[j]]+1);
			}
			for(int i=1;i<=top;++i){
				s1.set(1,1,n,s1.p[stk[i]],f[stk[i]]);
				s2.set(1,1,n,s2.p[stk[i]],f[stk[i]]);
			}
		}
		printf("%d\n",s1.se[1]);
	}
}