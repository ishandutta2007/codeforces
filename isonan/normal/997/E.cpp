#include <cstdio>
#include <vector>

struct point{int mn,cntmn;}se[960001];
int n,q,p[120001],stk1[120001],top1,stk2[120001],top2,lazy[960001],time[960001];
long long ans[960001],fin[120001];
std::vector<std::pair<int,int> >vec[120001];
point merge(point a,point b){return (a.mn!=b.mn)?(a.mn<b.mn?a:b):(point){a.mn,a.cntmn+b.cntmn};}
void add(int root,int x){se[root].mn+=x,lazy[root]+=x;}
void getans(int root,int x){
	ans[root]+=1ll*se[root].cntmn*x;
	time[root]+=x;
}
void spread(int root){
	if(lazy[root]){
		add(root<<1,lazy[root]);
		add(root<<1|1,lazy[root]);
		lazy[root]=0;
	}
	if(time[root]){
		if(se[root].mn==se[root<<1].mn)getans(root<<1,time[root]);
		if(se[root].mn==se[root<<1|1].mn)getans(root<<1|1,time[root]);
		time[root]=0;
	}
}
void pushup(int root){
	se[root]=merge(se[root<<1],se[root<<1|1]);
	ans[root]=ans[root<<1]+ans[root<<1|1];
}
void update(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		add(root,x);
		return;
	}
	spread(root);
	update(root<<1,l,(l+r)>>1,el,er,x);
	update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
	pushup(root);
}
void addans(int root,int l,int r,int el,int er){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		if(se[root].mn==0)getans(root,1);
		return;
	}
	spread(root);
	addans(root<<1,l,(l+r)>>1,el,er);
	addans(root<<1|1,((l+r)>>1)+1,r,el,er);
	pushup(root);
}
long long query(int root,int l,int r,int el,int er){
	spread(root);
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return ans[root];
	return query(root<<1,l,(l+r)>>1,el,er)+query(root<<1|1,((l+r)>>1)+1,r,el,er);
}
void build(int root,int l,int r){
	se[root].cntmn=r-l+1;
	if(l==r)return;
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	pushup(root);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	scanf("%d",&q);
	for(int i=1,l,r;i<=q;i++)scanf("%d%d",&l,&r),vec[r].push_back(std::make_pair(l,i));
	build(1,1,n);
	for(int i=1;i<=n;i++){
		while(top1&&p[stk1[top1]]<p[i]){
			update(1,1,n,stk1[top1-1]+1,stk1[top1],p[i]-p[stk1[top1]]);
			--top1;
		}
		stk1[++top1]=i;
		while(top2&&p[stk2[top2]]>p[i]){
			update(1,1,n,stk2[top2-1]+1,stk2[top2],p[stk2[top2]]-p[i]);
			--top2;
		}
		stk2[++top2]=i;
		if(i>1)update(1,1,n,1,i-1,-1);
		addans(1,1,n,1,i);
		for(auto it=vec[i].begin();it!=vec[i].end();++it)
			fin[it->second]=query(1,1,n,it->first,i);
	}
	for(int i=1;i<=q;i++)printf("%I64d\n",fin[i]);
}