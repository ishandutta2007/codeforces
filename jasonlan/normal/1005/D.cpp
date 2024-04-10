#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=301000;
int n,f[3];
char ch[maxn];
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	f[0]=0;f[1]=f[2]=-1;
	for(register int i=1,sum=0,fx=0;i<=n;++i){
		sum=(sum+ch[i]-'0')%3;
		fx=max(fx,f[sum]+1);
		f[sum]=fx;
		if(i==n)printf("%d",fx);
	}
	return 0;
}