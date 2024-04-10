#include <cstdio>
#include <cstring>

int f[100010][11],n;
long long ans;
char str[100010];
int main(){
	scanf("%s",str+1);
	for(int i=strlen(str+1);i;--i){
		for(int j=(str[i]-'0')+1;j<=10;j++)
			f[i][j]=f[i+1][(((j*(j-1))>>1)+(str[i]-'0')+10)%11]+1;
		if(str[i]>'0')ans+=f[i+1][str[i]-'0']+1;
	}
	printf("%I64d\n",ans);
}