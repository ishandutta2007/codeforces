#include <cstdio>
#include <cstdlib>
#include <algorithm>

int n,a[100001],Div[11],top,choose[11],Top,g[100001][21],loga[100001];
int ind[11][100001];
bool vis[100001];
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
int query(int l,int r){
	if(l>r)return 0;
	int k=loga[r-l+1];
	return gcd(g[l][k],g[r-(1<<k)+1][k]);
}
int main(){
	scanf("%d",&n);
	loga[0]=-1;
	for(int i=1;i<=n;i++)loga[i]=loga[i>>1]+1;
	srand(n*19260817);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)g[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			g[i][j]=gcd(g[i][j-1],g[i+(1<<(j-1))][j-1]);
	if(query(1,n)!=1){
		puts("NO");
		return 0;
	}
	for(int i=2;i*i<=a[1];i++)
		if(a[1]%i==0){
			Div[++top]=i;
			while(a[1]%i==0)a[1]/=i;
		}
	if(a[1]>1)Div[++top]=a[1];
	for(int i=1;i<=top;i++)
		for(int j=2;j<=n;j++)
			if(a[j]%Div[i])ind[i][++ind[i][0]]=j;
	vis[1]=1;
	for(int i=1;i<=100000;i++){
		Top=0;
		choose[0]=1;
		for(int j=1;j<=top;j++){
			choose[++Top]=ind[j][(1ll*rand()*rand())%ind[j][0]+1];
			if(vis[choose[Top]])--Top;
			vis[choose[Top]]=1;
		}
		choose[Top+1]=n+1;
		if(Top<n-1){
			std::sort(choose+1,choose+Top+1);
			int ans=0;
			for(int j=1;j<=Top+1;j++)
				ans=gcd(ans,query(choose[j-1]+1,choose[j]-1));
			if(ans==1){
				puts("YES");
				for(int i=1;i<=n;i++)printf("%d ",vis[i]+1);
				putchar('\n');
				return 0;
			}
		}
		for(int j=1;j<=Top;j++)vis[choose[j]]=0;
	}
	puts("NO");
}