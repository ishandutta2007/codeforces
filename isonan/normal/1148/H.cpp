#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using std::swap;
#define int long long

int n;
int vec[200001];
std::vector<std::pair<int,int> >root[200001];
std::vector<int>l1[200001],l2[200001],r1[200001],r2[200001];
namespace segtree{
	int lson[30000001],rson[30000001],cnt;
	long long now[30000001];
	long long sum[30000001];
	void add(int &pos,int pre,int l,int r,int el,int er,int x){
		if(el>r||er<l)return;
		pos=++cnt;
		lson[pos]=lson[pre];
		rson[pos]=rson[pre];
		now[pos]=now[pre];
		sum[pos]=sum[pre]+1ll*(std::min(r,er)-std::max(l,el)+1)*x;
		if(el<=l&&er>=r){
			now[pos]+=x;
			return;
		}
		add(lson[pos],lson[pre],l,(l+r)>>1,el,er,x);
		add(rson[pos],rson[pre],((l+r)>>1)+1,r,el,er,x);
	}
	long long query(int pos,int l,int r,int el,int er){
		if(el>r||er<l)return 0ll;
		if(el<=l&&er>=r)return sum[pos];
		return query(lson[pos],l,(l+r)>>1,el,er)+query(rson[pos],((l+r)>>1)+1,r,el,er)+1ll*(std::min(r,er)-std::max(l,el)+1)*now[pos];
	}
}
using segtree::add;
using segtree::query;
int time[2000001];
void update(int root,int l,int r,int e,int x){
	if(l==r){
		time[root]=x;
		return;
	}
	if((l+r)>>1>=e)update(root<<1,l,(l+r)>>1,e,x);
	else update(root<<1|1,((l+r)>>1)+1,r,e,x);
	time[root]=std::min(time[root<<1],time[root<<1|1]);
}
int query(int root,int l,int r,int e){
	if(l==r)return l;
	if(time[root<<1]<e)return query(root<<1,l,(l+r)>>1,e);
	else return query(root<<1|1,((l+r)>>1)+1,r,e);
}
int now[4][200001];
void upd(int l1,int l2,int r1,int r2,int k){
	if(r1>r2)return;
//	printf("upd %d %d %d %d %d\n",l1,l2,r1,r2,k);
	::l1[k].push_back(l1);
	::l2[k].push_back(l2);
	::r1[k].push_back(r1);
	::r2[k].push_back(r2);
	int rt=(root[k].empty())?0:root[k].back().second;
	root[k].push_back(std::make_pair(r2,0));
	add(root[k].back().second,rt,1,n,l1,l2,r2-r1+1);
}
signed main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%lld",&n);
	long long lans=0,a,l,r,k;
	memset(now,-1,sizeof now);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld",&a,&l,&r,&k);
		(a+=lans)%=(n+1);
		((l+=lans)%=i)++;
		((r+=lans)%=i)++;
		if(l>r)swap(l,r);
		(k+=lans)%=(n+1);
//		printf("%d %d %d %d\n",a,l,r,k);
		vec[a]=i;
		update(1,0,n,a,i);
		if(~now[0][a]){
			upd(now[0][a],now[1][a],now[2][a],i-1,a);
			int l=now[0][a],r=now[1][a],p;
			now[0][a]=-1;
			p=query(1,0,n,l);
			if(~now[0][p]){
				upd(now[0][p],now[1][p],now[2][p],i-1,p);
				now[0][p]=-1;
			}
			p=query(1,0,n,r);
			int R=0;
			if(~now[0][p]){
				upd(now[0][p],now[1][p],now[2][p],i-1,p);
				R=now[1][p];
				now[0][p]=-1;
			}
//			printf("%d %d\n",r,p);
			for(;;){
				int tem=vec[p];
//				printf("%d %d %d\n",p,r,tem);
				now[0][p]=tem+1;
				now[1][p]=std::max(r,R);
				R=0;
				now[2][p]=i;
				if(tem<l)break;
				p=query(1,0,n,tem);
				r=tem;
			}
		}
//		for(int j=0;j<=n;j++)if(~now[0][j])printf("*%d %d %d %d\n",now[0][j],now[1][j],now[2][j],i);
		int p=(a==0);
		if(~now[0][p])upd(now[0][p],now[1][p],now[2][p],i-1,p),now[1][p]=now[2][p]=i;
		else now[0][p]=now[1][p]=now[2][p]=i;
		lans=0;
		if(root[k].size()){
			int now=std::upper_bound(root[k].begin(),root[k].end(),std::make_pair(r+1,-1ll))-root[k].begin();
			if(root[k].begin()->first<=r){
				lans+=query(root[k][now-1].second,1,n,l,r);
			}
			if(root[k].rbegin()->first>r){
				int L1=l1[k][now],L2=l2[k][now],R1=r1[k][now],R2=r2[k][now];
				if(L2>=l&&R1<=r)lans+=1ll*(L2-std::max(L1,l)+1)*(std::min(R2,r)-R1+1);
			}
		}
		if(~now[0][k]){
			int L1=now[0][k],L2=now[1][k],R1=now[2][k],R2=i;
//			printf("%d %d %d %d\n",L1,L2,R1,R2);
			if(L2>=l&&R1<=r)lans+=1ll*(L2-std::max(L1,l)+1)*(std::min(R2,r)-R1+1);
		}
		printf("%lld\n",lans);
	}
}