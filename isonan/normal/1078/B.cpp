#include <cstdio>
#include <algorithm>

int f[10001][101],n,cnt[101],ans,a[101];
int main(){
	scanf("%d",&n);
	int type=0;
	for(int i=1;i<=n;i++)scanf("%d",a+i),++cnt[a[i]];
	for(int i=1;i<=100;i++)if(cnt[i])++type;
	f[0][0]=1;
	for(int i=1;i<=100;i++){
		for(int j=10000;~j;--j)
			for(int k=1;k<=cnt[i]&&k*i<=j;k++)
				for(int l=100;~l;l--){
					f[j][l]+=f[j-k*i][l-k];
				}
	}
	for(int i=1;i<=100;i++)
		for(int j=1;j<=cnt[i];j++){
			if(f[i*j][j]==1)ans=std::max(ans,((j==cnt[i]&&type==2)||type==1)?n:j);
		}
	printf("%d\n",ans);
}