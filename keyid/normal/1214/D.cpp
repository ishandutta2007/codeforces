#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

mt19937 gen(time(NULL));
uniform_int_distribution <int> dis(1000000000,1000010000);

const int MAXL=1000005,MOD[2]={dis(gen),dis(gen)};

char s[MAXL];
int dp1[MAXL][2],dp2[MAXL][2];

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%s",s+i*m);
	dp1[0][0]=dp1[0][1]=1;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (s[i*m+j]!='#')
			{
				if (i>0)
					for (int k=0;k<2;k++)
						(dp1[i*m+j][k]+=dp1[(i-1)*m+j][k])%=MOD[k];
				if (j>0)
					for (int k=0;k<2;k++)
						(dp1[i*m+j][k]+=dp1[i*m+j-1][k])%=MOD[k];
			}
	if (dp1[n*m-1][0]==0&&dp1[n*m-1][1]==0)
	{
		printf("0");
		return 0;
	}
	dp2[n*m-1][0]=dp2[n*m-1][1]=1;
	for (int i=n-1;i>=0;i--)
		for (int j=m-1;j>=0;j--)
			if (s[i*m+j]!='#')
			{
				if (i+1<n)
					for (int k=0;k<2;k++)
						(dp2[i*m+j][k]+=dp2[(i+1)*m+j][k])%=MOD[k];
				if (j+1<m)
					for (int k=0;k<2;k++)
						(dp2[i*m+j][k]+=dp2[i*m+j+1][k])%=MOD[k];
			}
	int cnt=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (s[i*m+j]!='#')
			{
				bool flag=true;
				for (int k=0;k<2;k++)
					if ((LL)dp1[i*m+j][k]*dp2[i*m+j][k]%MOD[k]!=dp2[0][k])
					{
						flag=false;
						break;
					}
				if (flag)
					cnt++;
			}
	assert(cnt>=2);
	printf(cnt<3?"2":"1");
	return 0;
}