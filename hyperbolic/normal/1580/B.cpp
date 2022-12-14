#include <stdio.h>
#include <vector>
int a,b,c;
long long int MOD;

long long int Comb[110][110];
long long int comb(int a, int b)
{
	if(a==b) return 1;
	if(b==0) return 1;
	if(Comb[a][b]!=-1) return Comb[a][b];
	return Comb[a][b] = (comb(a-1,b-1)+comb(a-1,b))%MOD;
}

int check[110][110];
std::vector<long long int> ans[110][110];
void func(int k, int h)
{
	if(check[k][h]) return;
	
	if(k==0)
	{
		ans[k][h].push_back(1%MOD);
		check[k][h] = 1;
		return;
	}
	
	int start = 0;
	if(h==b) start++;
	for(int i=0;i<=k-1;i++)
	{
		func(i,h+1);
		func(k-i-1,h+1);
		
		while(ans[k][h].size()<=start+ans[i][h+1].size()+ans[k-i-1][h+1].size()-2) ans[k][h].push_back(0);
		
		for(int j1=0;j1<ans[i][h+1].size();j1++)
		{
			for(int j2=0;j2<ans[k-i-1][h+1].size();j2++)
			{
				long long int t = ans[i][h+1][j1]*ans[k-i-1][h+1][j2];
				t %= MOD;
				t *= comb(k-1,i), t%= MOD;
				ans[k][h][start+j1+j2] += t, ans[k][h][start+j1+j2] %= MOD;
			}
		}
	}
	check[k][h] = 1;
}

int main()
{
	scanf("%d%d%d%lld",&a,&b,&c,&MOD);
	for(int i=0;i<=a;i++) for(int j=0;j<=a;j++) Comb[i][j] = -1;
	
	func(a,1);
	
	if(ans[a][1].size()>=c+1) printf("%lld",ans[a][1][c]%MOD);
	else printf("0");
}