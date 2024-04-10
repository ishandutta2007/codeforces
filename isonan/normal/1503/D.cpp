#include <cstdio>
#include <cstdlib>
#include <algorithm>

int f[400001],n,a[200001],b[200001],x[400001][2];
bool rev[200001];
std::vector<std::pair<int,int> >vec[2000001];
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return;
	f[u]=v;
	x[v][0]+=x[u][0];
	x[v][1]+=x[u][1];
}
int now;
void add(int root,int l,int r,int e,std::pair<int,int>x){
	vec[root].push_back(x);
	if(l==r)return;
	if((l+r)>>1>=e)add(root<<1,l,(l+r)>>1,e,x);
	else add(root<<1|1,((l+r)>>1)+1,r,e,x);
}
int oth(int x){return x<=n?x+n:(x-n);}
void Merge(int root,int l,int r,int el,int er,int v){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		int p=0;
		for(int i=0;i<vec[root].size();++i){
			if(vec[root][i].second<=now)continue;
			merge(v,oth(vec[root][i].first));
			merge(oth(v),vec[root][i].first);
			p=std::max(p,vec[root][i].second);
		}
		vec[root].clear();
		if(p)vec[root].push_back(std::make_pair(oth(v),p));
		return;
	}
	Merge(root<<1,l,(l+r)>>1,el,er,v);
	Merge(root<<1|1,((l+r)>>1)+1,r,el,er,v);
}
int ord[400001];
int main(){
	scanf("%d",&n);
	int l=-0x7f7f7f7f,r=0x7f7f7f7f;
	for(int i=1;i<=n;++i){
		scanf("%d%d",a+i,b+i);
		if(a[i]>b[i])std::swap(a[i],b[i]),rev[i]=1;
		l=std::max(l,a[i]);
		r=std::min(r,b[i]);
		ord[a[i]]=ord[b[i]]=i;
	}
	for(int i=1;i<=n;++i)x[i][0]=x[oth(i)][1]=1;
	if(l>=r){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=(n<<1);++i){
		now=i;
		int u=ord[i];
		if(i==a[u]){
			add(1,1,n,a[u],std::make_pair(rev[u]?u:oth(u),b[u]));
		}
		else{
			Merge(1,1,n,a[u],b[u],rev[u]?u:oth(u));
		}
	}
	for(int i=1;i<=n;++i)if(find(i)==find(oth(i))){
		puts("-1");
		return 0;
	}
	int ans=0;
	for(int i=1;i<=(n<<1);++i)
		if(!f[i])ans+=std::min(x[i][0],x[i][1]);
	printf("%d",ans>>1);
}