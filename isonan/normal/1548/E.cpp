#include <cstdio>
#include <vector>
#include <algorithm>

int n,m,x,a[200010],b[200010],ord[200010];
int st1[200010][21],st2[200010][21],Log[200010];
int cmp1(int l,int r){return a[l]<a[r]?l:r;}
int cmp2(int l,int r){return a[l]>a[r]?l:r;}
int cmp4(int l,int r){return b[l]>b[r]?l:r;}
bool cmp3(int l,int r){
	return b[l]>b[r];
}
int query1(int l,int r){
	int k=Log[r-l+1];
	return cmp1(st1[l][k],st1[r-(1<<k)+1][k]);
}
int query2(int l,int r){
	int k=Log[r-l+1];
	return cmp2(st2[l][k],st2[r-(1<<k)+1][k]);
}
int query4(int l,int r){
	if(l>r)return 0;
	int k=Log[r-l+1];
	return cmp4(st2[l][k],st2[r-(1<<k)+1][k]);
}
std::vector<std::pair<int,int> >que[200100];
long long ans;
void addquery(int l,int r,int v){
//	printf("addquery %d %d %d\n",l,r,v);
	if(l>r||r<=0)return;
	l=std::max(l,1);
	r=std::min(r,200000);
	que[l].push_back(std::make_pair(v,1));
	que[r+1].push_back(std::make_pair(v,-1));
}
void solve(int l,int r){
	if(l>r)return;
	int o=0x7f7f7f7f;
	if(l>1)o=std::min(o,a[l-1]);
	if(r<n)o=std::min(o,a[r+1]);
	int mid=query2(l,r),mn=query1(l,r);
	solve(l,mid-1);
	solve(mid+1,r);
	addquery(x-o+1,x-a[mid],x-a[mn]);
}
int num[200010],c[200100];
void update(int ind,int num){
	for(;ind;ind-=ind&-ind)c[ind]+=num;
}
int query(int ind){
	ind=std::max(ind,0);
	++ind;
	int tot=0;
	for(;ind<=200010;ind+=ind&-ind)tot+=c[ind];
	return tot;
}
int B[200010];
int stk[200010],top;
int main(){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=2;i<=n||i<=m;++i)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int j=1;j<=m;++j)scanf("%d",b+j);
	for(int i=1;i<=n;++i)st1[i][0]=i,st2[i][0]=i;
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			st1[i][j]=cmp1(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
			st2[i][j]=cmp2(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
	solve(1,n);
	for(int i=1;i<=m;++i)num[i]=i;
	std::sort(num+1,num+m+1,cmp3);
	for(int i=1;i<=m;++i)ord[num[i]]=i;
	for(int i=1;i<=m;++i)st2[i][0]=i;
	for(int j=1;(1<<j)<=m;++j)
		for(int i=1;i+(1<<j)-1<=m;++i)
			st2[i][j]=cmp4(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=m;++i)B[i]=200010;
	for(int i=1;i<=m;++i){
		while(top&&b[stk[top]]>=b[i])--top;
//		printf("%d %d\n",i,stk[top]);
		if(top){
			B[i]=std::min(B[i],b[query4(stk[top]+1,i-1)]);
//			if(i==7)printf("%d\n",query4(i+1,stk[top]-1));
		}
		stk[++top]=i;
	}
	top=0;
	for(int i=m;i;--i){
		while(top&&b[stk[top]]>b[i])--top;
//		printf("%d %d\n",i,stk[top]);
		if(top){
			B[i]=std::min(B[i],b[query4(i+1,stk[top]-1)]);
//			if(i==7)printf("%d\n",query4(i+1,stk[top]-1));
		}
		stk[++top]=i;
	}
//	for(int i=1;i<=m;++i)printf("%d ",B[i]);putchar('\n');
	for(int i=200000,now=1;i;--i){
		while(now<=m&&b[num[now]]==i){
			int u=num[now];
			update(B[u],1);
			++now;
		}
		for(int j=0;j<que[i].size();++j){
			ans+=que[i][j].second*query(que[i][j].first);
//			printf("%d %d %d %d\n",i,que[i][j].first,que[i][j].second,que[i][j].second*query(que[i][j].first));
		}
	}
	printf("%lld\n",ans);
}