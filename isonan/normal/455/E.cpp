#include <cstdio>
#include <vector>

int n,a[100001],m,S[100001],b[100001];
std::vector<int>se[600001];
bool chk(int x,int y,int z){
	return 1ll*(b[x]-b[y])*(a[z]-a[y])>=1ll*(b[y]-b[z])*(a[y]-a[x]);
}
void build(int root,int l,int r){
	if(l==r){
		se[root].push_back(l);
		return;
	}
	build(root<<1,l,(l+r)>>1);
	build(root<<1|1,((l+r)>>1)+1,r);
	for(int i=0,j=0;i<se[root<<1].size()||j<se[root<<1|1].size();){
		int u;
		if(i==se[root<<1].size())u=se[root<<1|1][j++];
		else if(j==se[root<<1|1].size())u=se[root<<1][i++];
		else if(a[se[root<<1][i]]>=a[se[root<<1|1][j]])u=se[root<<1][i++];
		else u=se[root<<1|1][j++];
		if(!se[root].empty()&&a[se[root].back()]==a[u]){
			if(b[se[root].back()]>b[u])se[root].pop_back();
			else continue;
		}
		while(se[root].size()>1&&chk(se[root][se[root].size()-2],se[root].back(),u))se[root].pop_back();
		se[root].push_back(u);
	}
}
bool out;
int query(int root,int l,int r,int el,int er,int x){
	if(el>r||er<l)return 0x7f7f7f7f;
	if(el<=l&&er>=r){
//		printf("%d %d ",l,r);
		int l=1,r=(int)se[root].size()-1,mid,ans=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[se[root][mid]]*x+b[se[root][mid]]<=a[se[root][mid-1]]*x+b[se[root][mid-1]])ans=mid,l=mid+1;
			else r=mid-1;
		}
//		printf("%d\n",se[root][ans]);
		return a[se[root][ans]]*x+b[se[root][ans]];
	}
	return std::min(query(root<<1,l,(l+r)>>1,el,er,x),query(root<<1|1,((l+r)>>1)+1,r,el,er,x));
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),S[i]=a[i]+S[i-1];
	for(int i=1;i<=n;i++)b[i]=a[i]*i-S[i];
	build(1,1,n);
	int m;
	scanf("%d",&m);
	for(int fd=1,i,j;fd<=m;fd++){
		scanf("%d%d",&i,&j);
		printf("%d\n",S[j]+query(1,1,n,j-i,j,i-j));
	}
}