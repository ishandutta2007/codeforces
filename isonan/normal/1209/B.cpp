#include <cstdio>
#include <algorithm>

int n,light[100001],a[101],b[101];
char str[101];
int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
	for(int i=1;i<=n;i++){
		int stat=(str[i]=='1');
		for(int j=0;j<=10000;j++){
			if((j%a[i])==(b[i]%a[i])&&j>=b[i])stat^=1;
			light[j]+=stat;
		}
	}
	int ans=0;
	for(int i=0;i<=10000;i++){
		ans=std::max(ans,light[i]);
	}
	printf("%d\n",ans);
}