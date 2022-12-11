#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mod=1e9+7;
int n,ans;
char ch[710];
int f[2][710][710];
void qmod(int &x){
	if(x>=mod)x-=mod;
}
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(register int i=1;i<=9;++i){
		memset(f,0,sizeof(f));
		for(register int j=0;j<=ch[1]-'0';++j)
			++f[j<ch[1]-'0'][1][j>=i];
		for(register int j=1;j<n;++j)
			for(register int k=0;k<=j;++k)
				for(register int s=0;s<2;++s)
					for(register int l=0;l<=(s?9:ch[j+1]-'0');++l)
						qmod(f[s|(l<ch[j+1]-'0')][j+1][k+(l>=i)]+=f[s][j][k]);
		for(register int j=0,tmp=0;j<=n;++j){
			qmod(ans+=1ll*tmp*(f[0][n][j]+f[1][n][j])%mod);
			tmp=(tmp*10ll+1)%mod;
		}
	}
	printf("%d",ans);
	return 0;
}