#include <cstdio>
#include <vector>
#include <algorithm>

int n,m,p,a[1000001];
struct func{
	std::vector<long long>vec;
	long long S;
	int ind(long long x){
		return std::upper_bound(vec.begin(),vec.end(),x)-vec.begin(); 
	}
	long long f(long long x){
		return x+S-1ll*ind(x)*p;
	}
}f[1000010];
long long tem1[1000001],tem2[1000001];
func merge(func a,func b){
	func c;
	c.S=a.S+b.S;
	c.vec.resize(a.vec.size()+b.vec.size());
	for(int i=0;i<c.vec.size();i++)c.vec[i]=1e18;
	for(int i=0;i<a.vec.size();i++)tem1[i]=a.vec[i]+a.S-1ll*(i+1)*p;
	int last=0;
	for(int i=0;i<b.vec.size();i++)if(b.vec[i]<a.vec[0]+a.S)c.vec[i]=std::min(c.vec[i],b.vec[i]-a.S),last=i;
	for(int i=0,cnt=0;i<a.vec.size();i++){
		for(int j=std::max(0,last-1);j<b.vec.size();j++){
			if(a.vec[i]+a.S-1ll*(i+1)*p<=b.vec[j]&&(i==a.vec.size()-1||a.vec[i+1]-1+a.S-1ll*(i+1)*p>=b.vec[j]))
				c.vec[i+j+1]=std::min(c.vec[i+j+1],b.vec[j]-a.S+1ll*(i+1)*p),last=j;
			if(i<a.vec.size()-1&&a.vec[i+1]-1+a.S-1ll*(i+1)*p<b.vec[j]){
				break;
			}
		}
		while(cnt<b.vec.size()&&b.vec[cnt]<=tem1[i])++cnt;
		c.vec[i+cnt]=std::min(c.vec[i+cnt],a.vec[i]);
	}
	return c;
}
long long que[200001];
std::vector<int>vec[6000010];
void solve(int root,int l,int r){
	if(l==r){
		f[l].vec.push_back(1ll*p-1ll*a[l]);
		f[l].S=a[l];
	}
	else{
		solve(root<<1,l,(l+r)>>1);
		solve(root<<1|1,((l+r)>>1)+1,r);
		f[l]=merge(f[l],f[((l+r)>>1)+1]);
		f[((l+r)>>1)+1].vec.clear();
	}
	for(int i=0;i<vec[root].size();i++){
		que[vec[root][i]]=f[l].f(que[vec[root][i]]);
	}
}
void add(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return;
	if(el<=l&&er>=r){
		vec[root].push_back(x);
		return;
	}
	add(root<<1,l,(l+r)>>1,el,er,x);
	add(root<<1|1,((l+r)>>1)+1,r,el,er,x);
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		que[i]=0;
		add(1,1,n,l,r,i);
	}
	solve(1,1,n);
	for(int i=1;i<=m;i++)printf("%lld\n",que[i]);
}