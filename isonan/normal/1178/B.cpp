#include <cstdio>
#include <cstring>

char str[1000001];
long long f[1000001],g[1000010];
int main(){
	scanf("%s",str+1);
	int n=strlen(str+1);
	for(int i=2;i<=n;i++)f[i]=f[i-1]+(str[i]=='v'&&str[i-1]=='v');
	for(int i=n-1;i;i--)g[i]=g[i+1]+(str[i]=='v'&&str[i+1]=='v');
	long long ans=0;
	for(int i=1;i<=n;i++)
		if(str[i]=='o')ans+=f[i-1]*g[i+1];
	printf("%I64d",ans);
}