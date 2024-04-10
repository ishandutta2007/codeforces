#include <bits/stdc++.h>

int a[400001],sa[400001],rank[400001],tax[2000001],tp[400001],n,m,q,Log[400001];
int ans[400001];
int st[200001][21];
void Qsort(){
	for(int i=0;i<=m;i++)tax[i]=0;
	for(int i=1;i<=n;i++)++tax[rank[i]];
	for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
	for(int i=n;i;i--)sa[tax[rank[tp[i]]]--]=tp[i];
}
void init(){
	for(int i=1;i<=n;i++)rank[i]=a[i],tp[i]=i;
	Qsort();
	for(int p=1,w=1;p<n;m=p,w<<=1){
		p=0;
		for(int i=1;i<=w;i++)tp[++p]=n-w+i;
		for(int i=1;i<=n;i++)if(sa[i]>w)tp[++p]=sa[i]-w;
		Qsort();
		std::swap(rank,tp);
		rank[sa[1]]=p=1;
		for(int i=2;i<=n;i++)
			rank[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
	}
	for(int i=1,k=0;i<=n;i++){
		if(k)--k;
		if(rank[i]==n)continue;
		while(i+k<=n&&a[i+k]==a[sa[rank[i]+1]+k])++k;
		st[rank[i]][0]=k;
	}
	for(int j=1;(1<<j)<n;j++)
		for(int i=1;i+(1<<j)-1<n;i++)
			st[i][j]=std::min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	--r;
	int k=Log[r-l+1];
	return std::min(st[l][k],st[r-(1<<k)+1][k]);
}
int c[400001];
void update(int ind){for(;ind<=n;ind+=ind&-ind)++c[ind];}
int Query(int ind){
	int tot=0;
	for(;ind;ind-=ind&-ind)tot+=c[ind];
	return tot;
}
struct que{
	int l,r,ord,v;
};
std::vector<que>vec[400001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<n;i++)a[i]=a[i+1]-a[i];
	--n;
	for(int i=1;i<=n;i++)a[i+n]=-a[i];
	memcpy(tp,a,sizeof tp);
	n<<=1;
	std::sort(tp+1,tp+n+1);
	m=std::unique(tp+1,tp+n+1)-tp-1;
	for(int i=1;i<=n;i++)a[i]=std::lower_bound(tp+1,tp+m+1,a[i])-tp;
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
	for(int i=2;i<=n;i++)Log[i]=Log[i>>1]+1;
	init();
//	for(int i=1;i<=n;i++)printf("%d %d %d\n",i,sa[i],rank[i]);
//	for(int l,r;;){
//		scanf("%d%d",&l,&r);
//		l=rank[l],r=rank[r];
//		if(l>r)std::swap(l,r);
//		printf("%d\n",query(l,r));
//	}
	scanf("%d",&q);
	n=(n>>1)+1;
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		if(l==r){
			ans[i]=n-1;
			continue;
		}
		int L=rank[l+n-1],R=rank[l+n-1];
		for(int j=20;~j;--j)
			if(L-(1<<j)>=1&&query(L-(1<<j),rank[l+n-1])>=r-l)L-=1<<j;
		for(int j=20;~j;--j)
			if(R+(1<<j)<=((n-1)<<1)&&query(rank[l+n-1],R+(1<<j))>=r-l)R+=1<<j;
		vec[L-1].push_back((que){1,(l<<1)-r-1,i,-1});
		vec[L-1].push_back((que){r+1,n-r+l,i,-1});
		vec[R].push_back((que){1,(l<<1)-r-1,i,1});
		vec[R].push_back((que){r+1,n-r+l,i,1});
	}
	for(int i=1;i<=((n-1)<<1);i++){
		if(sa[i]>=1&&sa[i]<n)update(sa[i]);
		for(int j=0;j<vec[i].size();j++){
			int l=vec[i][j].l,r=vec[i][j].r;
			if(l>r)continue;
			ans[vec[i][j].ord]+=vec[i][j].v*(Query(r)-Query(l-1));
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}