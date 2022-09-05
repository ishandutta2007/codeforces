#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
const int N=50+5,M=500,INF=1e5;
int dp[N][M*2][M*2];
char str[N];

int main()
{
	scanf("%s",str+1);
	int n=strlen(str+1);
	reverse(str+1,str+n+1);
	str[++n]='0';
	memset(dp,16,sizeof(dp));
	dp[0][M][M]=0;
	for(int i=1;i<=n;++i)
	for(int j=0;j<M*2;++j)
	for(int k=0;k<M*2;++k)
	{
		int f0=dp[i-1][j][k];
		if(f0>=INF)continue;
		for(int nk=(str[i]-'0'-j+INF)%10;nk<M*2;nk+=10)
		{
			int s=j-M+nk-M;
			int nj=s/10-(s%10<0);
			int nf=f0+abs(nk-M);
			if((nk-M>0)==(k-M>0))
			{ 
				if(nk-M>0)
					nf+=max(0,(nk-k)*(i-1)*2);
				else  
					nf+=max(0,(k-nk)*(i-1)*2);
			} 
			else
				nf+=max(0,abs(nk-M)*(i-1)*2); 
			if(abs(nj)<M)chmin(dp[i][nj+M][nk],nf);
		}
	}
	cout<<*min_element(dp[n][M],dp[n][M]+M*2)<<endl;
}