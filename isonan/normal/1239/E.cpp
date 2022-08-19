#include <bitset>
#include <cstdio>
#include <algorithm>

int n,a[101],sum,ans=0x7f7f7f7f;
int fin[2][101];
std::bitset<1200001>f[49][25];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=(n<<1);i++)scanf("%d",a+i);
	std::sort(a+1,a+(n<<1)+1);
	for(int i=3;i<=(n<<1);i++)sum+=a[i];
	f[0][0].set(0);
	for(int i=1;i<=(n<<1)-2;i++)
		for(int j=0;j<=n-1;j++){
			f[i][j]=f[i-1][j];
			if(j)f[i][j]|=f[i-1][j-1]<<a[i+2];
		}
	for(int i=0;i<=sum;i++)if(f[(n<<1)-2][n-1][i])ans=std::min(ans,std::max(i,sum-i));
	fin[0][1]=a[1];
	fin[1][n]=a[2];
	int top1=n,top2=1,now=n-1;
	for(int i=(n<<1);i>=3;i--)
		if(ans>=a[i]&&now&&f[i-3][now-1][ans-a[i]])fin[0][top1--]=a[i],ans-=a[i],--now;
		else fin[1][top2++]=a[i];
	for(int i=0;i<2;i++,putchar('\n'))
		for(int j=1;j<=n;j++)
			printf("%d ",fin[i][j]);
}