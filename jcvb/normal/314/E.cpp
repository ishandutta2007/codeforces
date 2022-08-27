#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;

int n;
char s[100005];
int f[100005];
int main()
{
	scanf("%d",&n);
	if(n&1){
		printf("0\n");
		return 0;
	}
	scanf("%s",s+1);
	int cnt=0;
	f[0]=1;
	int k=n/2;
	for (int i=1;i<=n;i++){
		if(s[i]=='?'){
			if(!(i&1))f[0]=f[1];
			for (int j=i&1?1:2;j<=k;j+=2)f[j]=f[j-1]+f[j+1];
		}else{
			cnt++;
			for (int j=((k&1)==(i&1))?k:k-1;j>=1;j--)f[j]=f[j-1];
			f[0]=0;
		}
	}
	int a=f[0];
	cnt=k-cnt;
	while(cnt-->0)a*=25;
	printf("%u",a);
	return 0;
}