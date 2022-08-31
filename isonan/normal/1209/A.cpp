#include <cstdio>

int n,a[101],cnt[101];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),cnt[a[i]]=1;
	int ans=0;
	for(int i=1;i<=100;i++)
		if(cnt[i]){
			++ans;
			for(int j=i;j<=100;j+=i)cnt[j]=0;
		}
	printf("%d\n",ans);
}