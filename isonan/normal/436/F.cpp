#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>

int n,w,a[100001],b[100001];
struct ktt{
	long long t[1000001],lazy[1000001],a[200001];
	std::pair<long long,long long>mx[1000001];
	int pos[1000001];
	void pushdown(int x,int y){
		lazy[x]+=y;
		t[x]-=y;
		mx[x].first+=mx[x].second*y;
	}
	void spread(int x){
		if(lazy[x]){
			pushdown(x<<1,lazy[x]);
			pushdown(x<<1|1,lazy[x]);
			lazy[x]=0;
		}
	}
	long long calc(const std::pair<long long,long long> &a,const std::pair<long long,long long> &b){
		if(a.second>=b.second)return 1e18;
		return (a.first-b.first)/(b.second-a.second);
	}
	void pushup(int x){
		t[x]=std::min(t[x<<1],t[x<<1|1]);
		if(mx[x<<1].first<mx[x<<1|1].first){
			mx[x]=mx[x<<1|1];
			t[x]=std::min(t[x],calc(mx[x<<1|1],mx[x<<1]));
		}
		else{
			mx[x]=mx[x<<1];
			t[x]=std::min(t[x],calc(mx[x<<1],mx[x<<1|1]));
		}
	}
	void rebuild(int x){
		if(t[x]>=0)return;
		spread(x);
		rebuild(x<<1);
		rebuild(x<<1|1);
		pushup(x);
	}
	void update(int root,int l,int r,int el,int er,long long x){
		if(el>r||er<l)return;
		if(el<=l&&er>=r){
			pushdown(root,x);
			if(t[root]<x)rebuild(root);
			return;
		}
		spread(root);
		update(root<<1,l,(l+r)>>1,el,er,x);
		update(root<<1|1,((l+r)>>1)+1,r,el,er,x);
		pushup(root);
	}
	long long query(int root,int l,int r,int el,int er){
		if(el>r||er<l)return -1e18;
		spread(root);
//		printf("query %d %d %lld\n",l,r,mx[root].first);
		if(el<=l&&er>=r)return mx[root].first;
		return std::max(query(root<<1,l,(l+r)>>1,el,er),query(root<<1|1,((l+r)>>1)+1,r,el,er));
	}
	void set(int root,int l,int r,int e,long long x){
		if(l==r){
			mx[root].first=x;
			return;
		}
		spread(root);
		if((l+r)>>1>=e)set(root<<1,l,(l+r)>>1,e,x);
		else set(root<<1|1,((l+r)>>1)+1,r,e,x);
		pushup(root);
//		printf("set %d %d %lld\n",l,r,mx[root].first);
	}
	void build(int root,int l,int r){
		if(l==r){
			mx[root].second=a[l];
//			printf("\t%d %d %lld\n",root,l,mx[root].first);
			t[root]=1e18;
			return;
		}
		build(root<<1,l,(l+r)>>1);
		build(root<<1|1,((l+r)>>1)+1,r);
		pushup(root);
	}
}t;
std::vector<int>vec[100010];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
void write(long long x){
	if(x>9)write(x/10);
	putchar((x%10)+'0');
}
int main(){
	n=read(),w=read();
	int mx=0;
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read();
		mx=std::max(mx,b[i]);
		vec[b[i]].push_back(a[i]);
	}
	for(int i=1;i<=100000;i++)t.a[i]=i;
	t.build(1,1,100000);
	int cnt=n;
	for(int i=0;i<=mx+1;i++){
		write(1ll*cnt*i*w+t.mx[1].first),putchar(' ');
		write(t.mx[1].second),putchar('\n');
		for(int j=0;j<vec[i].size();j++)
			--cnt,t.update(1,1,100000,1,vec[i][j],1);
	}
}