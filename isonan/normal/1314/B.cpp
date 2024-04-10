#include <cstdio>
#include <cstring>
#include <algorithm>

int n,k,f[400001][4];
int a[400001];
bool vis[400001];
int mx=0;
void getans(int root,int l,int r){
	mx=std::max(mx,root);
	f[root][2]=f[root][0]=f[root][1]=-n*10;
	f[root][3]=0;
	if(r-l+1==2){
		int cnt=vis[l]+vis[r];
		if(cnt==1){
			f[root][0]=f[root][1]=1;
		}
		else if(cnt==2){
			f[root][2]=1;
		}
		return;
	}
	getans(root<<1,l,(l+r)>>1);
	getans(root<<1|1,((l+r)>>1)+1,r);
	f[root][0]=std::max(f[root<<1][0],f[root<<1][3])+f[root<<1|1][0]+1;
	f[root][0]=std::max(f[root][0],std::max(f[root<<1|1][0],f[root<<1|1][3])+f[root<<1][0]+1);
	f[root][1]=std::max(f[root<<1][1],f[root<<1][3])+f[root<<1|1][1]+2;
	f[root][1]=std::max(f[root][1],std::max(f[root<<1|1][1],f[root<<1|1][3])+f[root<<1][1]+2);
	f[root][2]=std::max(
		f[root<<1][2]+std::max(std::max(f[root<<1|1][2],f[root<<1|1][1]),std::max(f[root<<1|1][0],f[root<<1|1][3])),
		f[root<<1|1][2]+std::max(std::max(f[root<<1][2],f[root<<1][1]),std::max(f[root<<1][0],f[root<<1][3]))
	);
	f[root][2]=std::max(f[root][2],std::max(
		f[root<<1][0]+f[root<<1|1][1],
		f[root<<1][1]+f[root<<1|1][0]
	));
	f[root][2]+=3;
//	printf("%d %d %d %d %d\n",l,r,f[root][0],f[root][1],f[root][2]);
}
int main(){
	scanf("%d%d",&n,&k);
	if(!k){
		puts("0");
		return 0;
	}
	for(int i=1;i<=k;i++)scanf("%d",a+i),vis[a[i]]=1;
	getans(1,1,1<<n);
	printf("%d\n",std::max(std::max(f[1][1]+1,f[1][0]+1),f[1][2]+1));
}