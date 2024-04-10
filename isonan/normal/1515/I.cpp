#include <cstdio>
#include <vector>
#include <algorithm>

int n,q,L[200001],cnt;
long long a[200001];
struct type{
	int ord,w,v;
}num[200001];
struct query{
	int l,r;
	long long k;
};
std::vector<query>vec[200001];
long long ans[200001],res[200001];
bool cmp(type a,type b){return a.v>b.v||(a.v==b.v&&a.w<b.w);}
struct segtree{
	long long lw[500001],lv[500001];
	std::pair<long long,int> mn[500001],mx[500001];
	void pushdown(int x,long long w,long long v){
		lw[x]+=w;
		lv[x]+=v;
		if(mn[x].second)mn[x].first+=w;
		if(mx[x].second)mx[x].first+=w;
	}
	void spread(int x){
//		printf("spread %d %lld %lld\n",x,lw[x],lv[x]);
		if(lv[x]||lw[x]){
			pushdown(x<<1,lw[x],lv[x]);
			pushdown(x<<1|1,lw[x],lv[x]);
			lw[x]=lv[x]=0;
		}
	}
	void pushup(int x){
		mn[x]=std::min(mn[x<<1],mn[x<<1|1]);
		mx[x]=std::max(mx[x<<1],mx[x<<1|1]);
	}
	void build(int root,int l,int r){
		mn[root]=std::make_pair(2e18,0);
		mx[root]=std::make_pair(-2e18,0);
		if(l==r)return;
		build(root<<1,l,(l+r)>>1);
		build(root<<1|1,((l+r)>>1)+1,r);
	}
	void add(int root,int l,int r,int e){
		if(l==r){
			mn[root]=mx[root]=std::make_pair(res[e],e);
			ans[e]-=lv[root];
			return;
		}
		spread(root);
//		printf("add %d %d %d\n",root,l,r);
		if((l+r)>>1>=e)add(root<<1,l,(l+r)>>1,e);
		else add(root<<1|1,((l+r)>>1)+1,r,e);
		pushup(root);
	}
	void del(int root,int l,int r,int e){
		if(l==r){
			res[e]=mn[root].first;
			mn[root]=std::make_pair(2e18,0);
			mx[root]=std::make_pair(-2e18,0);
			ans[e]+=lv[root];
			return;
		}
		spread(root);
		if((l+r)>>1>=e)del(root<<1,l,(l+r)>>1,e);
		else del(root<<1|1,((l+r)>>1)+1,r,e);
		pushup(root);
	}
	std::pair<long long,int> querymin(int root,int l,int r,int el,int er){
		if(el>r||er<l)return std::make_pair(2e18,0);
		if(el<=l&&er>=r)return mn[root];
		spread(root);
		return std::min(querymin(root<<1,l,(l+r)>>1,el,er),querymin(root<<1|1,((l+r)>>1)+1,r,el,er));
	}
	std::pair<long long,int> querymax(int root,int l,int r,int el,int er){
		if(el>r||er<l)return std::make_pair(-2e18,0);
		if(el<=l&&er>=r)return mx[root];
		spread(root);
		return std::max(querymax(root<<1,l,(l+r)>>1,el,er),querymax(root<<1|1,((l+r)>>1)+1,r,el,er));
	}
	void update(int root,int l,int r,int el,int er,long long w,long long v){
		if(el>r||er<l)return;
		if(el<=l&&er>=r){
			pushdown(root,w,v);
			return;
		}
		spread(root);
		update(root<<1,l,(l+r)>>1,el,er,w,v);
		update(root<<1|1,((l+r)>>1)+1,r,el,er,w,v);
		pushup(root);
	}
}se[19];
int top(long long x){
	for(int i=18;~i;--i)
		if(x>=(1<<i))return i;
	return -1;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%lld%d%d",a+i,&num[i].w,&num[i].v),num[i].ord=i;
	std::sort(num+1,num+n+1,cmp);
	for(int i=1,t,k,d;i<=q;++i){
		scanf("%d",&t);
		if(t<=2){
			scanf("%d%d",&k,&d);
			vec[d].push_back((query){L[d]+1,cnt,a[d]});
			L[d]=cnt; 
			a[d]=(t==1)?a[d]+k:a[d]-k;
		}
		else{
			scanf("%lld",res+(++cnt));
		}
	}
	for(int i=1;i<=n;++i)vec[i].push_back((query){L[i]+1,cnt,a[i]});
	for(int i=0;i<19;++i)se[i].build(1,1,cnt);
	for(int i=1;i<=cnt;++i)se[top(res[i])].add(1,1,cnt,i);
//	return 0;
	for(int i=1;i<=n;++i){
		int u=num[i].ord;
//		printf("%d\n",u);
		for(int j=0;j<(int)vec[u].size();++j){
			int L=vec[u][j].l,R=vec[u][j].r;
			long long k=vec[u][j].k;
			if(!k)continue;
//			printf("%d %d %d %d %lld\n",num[i].w,num[i].v,L,R,k);
			int x=top(num[i].w);
			for(;;){
				auto val=se[x].querymax(1,1,cnt,L,R);
				int now=val.second;
//				printf("*%d %d %d\n",x,now,num[i].w);
				if(!now||val.first<num[i].w)break;
				se[x].del(1,1,cnt,now);
				long long y=std::min(res[now]/num[i].w,k);
//				printf("%lld\n",y);
				res[now]-=y*num[i].w;
				ans[now]+=y*num[i].v;
				if(res[now])se[top(res[now])].add(1,1,cnt,now);
			}
			for(++x;x<19;++x){
				for(;;){
					auto val=se[x].querymin(1,1,cnt,L,R);
					int now=val.second;
//					printf("-%d %d\n",x,now);
					if(!now)break;
					long long y=std::min(val.first/num[i].w,k);
					if(top(val.first-num[i].w*y)==x){
						se[x].update(1,1,cnt,L,R,-y*num[i].w,y*num[i].v);
						break;
					}
					se[x].del(1,1,cnt,now);
					res[now]-=y*num[i].w;
					ans[now]+=y*num[i].v;
					if(res[now])se[top(res[now])].add(1,1,cnt,now);
				}
			}
		}
	}
	for(int i=0;i<19;++i)while(se[i].mn[1].second)se[i].del(1,1,cnt,se[i].mn[1].second);
	for(int i=1;i<=cnt;++i)printf("%lld\n",ans[i]);
}