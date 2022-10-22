#include <queue>
#include <vector>
#include <cstdio>
typedef long long ll;
const int Maxn=200000;
int n,m;
int a[Maxn+5],b[Maxn+5];
ll sum[Maxn+5];
std::vector<int> seg_l[Maxn+5],seg_r[Maxn+5];
namespace DSU{
	int fa[Maxn+5];
	void init(){
		for(int i=0;i<=n+1;i++){
			fa[i]=i;
		}
	}
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return;
		}
		fa[fa_y]=fa_x;
	}
}
std::queue<std::pair<int,int> > q;
void merge_seg(int l,int r){
	for(int i=DSU::find(l);i<=r;i=DSU::find(i)){
		for(int j:seg_r[i]){
			if(DSU::find(j)!=j){
				q.push(std::make_pair(i,j));
			}
		}
		for(int j:seg_l[i]){
			if(DSU::find(j)!=j){
				q.push(std::make_pair(j,i));
			}
		}
		DSU::merge(i+1,i);
	}
}
void solve(){
	while(!q.empty()){
		q.pop();
	}
	scanf("%d%d",&n,&m);
	DSU::init();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		seg_l[i].clear(),seg_r[i].clear();
	}
	seg_l[0].clear(),seg_r[0].clear();
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		sum[i]=sum[i-1]+a[i]-b[i];
	}
	for(int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		l--;
		seg_l[r].push_back(l),seg_r[l].push_back(r);
	}
	for(int i=0;i<=n;i++){
		if(sum[i]==0){
			merge_seg(i,i);
		}
	}
	while(!q.empty()){
		std::pair<int,int> u=q.front();
		q.pop();
		merge_seg(u.first,u.second);
	}
	if(DSU::find(0)>n){
		puts("YES");
	}
	else{
		puts("NO");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}