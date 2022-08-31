#include <cstdio>

int stat[10]={119,36,93,109,46,107,123,37,127,111},k,f[2010][2010],num[2010];
int ans[2010],n;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int tem=0;
		for(int j=0;j<7;j++)scanf("%1d",&tem),num[i]+=(1<<j)*tem; 
	}
	f[n+1][0]=1;
	for(int i=n;i;i--){
		for(int j=0;j<=k;j++){
			for(int l=0;l<10;l++)
				if((num[i]|stat[l])==stat[l]){
					int v=__builtin_popcount(stat[l])-__builtin_popcount(num[i]);
//					printf("%d %d %d\n",num[i],l,v);
					if(j>=v)f[i][j]|=f[i+1][j-v];//,printf("&%d %d %d\n",i,j,f[i][j]);
				}
					
		}
	}
	int sum=k;
	for(int i=1;i<=n;i++){
		bool cando=0;
		for(int j=9;~j;--j){
			if((num[i]|stat[j])==stat[j]){
				int v=__builtin_popcount(stat[j])-__builtin_popcount(num[i]);
//				printf("*%d %d %d %d\n",num[i],j,v,sum-v);
				if(sum>=v&&f[i+1][sum-v]){
					ans[i]=j;
					cando=1;
					sum-=v;
					break;
				}
			}
		}
		if(!cando){
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)putchar(ans[i]+'0');
}