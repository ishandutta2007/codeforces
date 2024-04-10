#include <cstdio>

int s[5001][5001],P=1000000007,n,k;
int mul(int a,int b){return (long long)a*b%P;}
int qsm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<=k;i++)s[i][1]=1;
	for(int i=2;i<=k;i++)
		for(int j=2;j<=i;j++)
			(s[i][j]=s[i-1][j-1]+mul(j,s[i-1][j]))%=P;
	long long ans=0;
	for(int i=0,com=1;i<=k&&i<=n;i++){
		ans+=mul(s[k][i],mul(com,qsm(2,n-i)));
		com=mul(com,n-i);
	}
	printf("%I64d\n",ans%P);
}