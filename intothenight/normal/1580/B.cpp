#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAXN 105
#define MAXN2 104
int n,m,k,mod,C[MAXN][MAXN],f[MAXN2][MAXN2][MAXN2];
signed main()
{
	cin>>n>>m>>k>>mod;
	for(int i=0;i<MAXN;C[i][0]=1,i++)
		for(int l=1;l<=i;l++)
			C[i][l]=(C[i-1][l]+C[i-1][l-1])%mod;
	for(int i=n+1;i;i--)
	{
		f[i][0][0]=1;
		vector<int>v[MAXN];
		for(int l=0;l<=n;l++)
			for(int j=0;j<=l;j++)
				if(f[i+1][l][j])
					v[l].push_back(j);
		for(int l=0;l<=n;l++)
			if(!v[l].empty())
				for(int j=0;j+l<=n;j++)
					if(!v[j].empty())
						for(auto x:v[l])
							for(auto y:v[j])
								(f[i][l+j+1][x+y+(i==m)]+=(ll)C[l+j][j]*f[i+1][l][x]%mod*f[i+1][j][y]%mod)%=mod;
	}
	printf("%d",f[1][n][k]);
	return 0;
}
/*
 102, 103, 104, 105, 106, 107, 108, 109, 110, 111
1294, 280, 265, 265, 280, 296, 296, 280, 296, 295
*/