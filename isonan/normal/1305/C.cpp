#include <cstdio>
#include <algorithm>

int n,a[200001],m,cnt[1001],mod[1000001];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m*m;i++)mod[i]=i%m;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	int ans=1;
	for(int i=0;i<m;i++)cnt[i]=1;
	for(int i=1;i<=n;i++){
		a[i]%=m;
		ans=mod[ans*cnt[mod[a[i]]]];
		for(int j=0;j<m;j++)cnt[j]=mod[cnt[j]*((j+m-(a[i]))%m)];
	}
	printf("%d\n",ans);
}