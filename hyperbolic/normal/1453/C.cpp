#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V[20];
char x[2010][2010];
long long int ans[20];

long long int abs(long long int k)
{
	return k>0?k:-k;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=9;i++) ans[i] = 0;
		for(int i=0;i<=9;i++) V[i].clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) V[x[i][j]-'0'].push_back(std::make_pair(i,j));
		
		for(int i=0;i<=9;i++)
		{
			int L=-1,R=-1,U=-1,D=-1;
			for(int j=0;j<V[i].size();j++)
			{
				if(L==-1) L = V[i][j].first;
				else L = L<V[i][j].first?L:V[i][j].first;
				if(R==-1) R = V[i][j].first;
				else R = R>V[i][j].first?R:V[i][j].first;
				if(U==-1) U = V[i][j].second;
				else U = U<V[i][j].second?U:V[i][j].second;
				if(D==-1) D = V[i][j].second;
				else D = D>V[i][j].second?D:V[i][j].second;
			}
			for(int j=0;j<V[i].size();j++)
			{
				long long int s1 = (long long int)(a-V[i][j].first)*abs(V[i][j].second-U);
				long long int s2 = (long long int)(V[i][j].first-1)*abs(V[i][j].second-U);
				long long int s3 = (long long int)(a-V[i][j].second)*abs(V[i][j].first-L);
				long long int s4 = (long long int)(V[i][j].second-1)*abs(V[i][j].first-L);
				long long int t1 = (long long int)(a-V[i][j].first)*abs(V[i][j].second-D);
				long long int t2 = (long long int)(V[i][j].first-1)*abs(V[i][j].second-D);
				long long int t3 = (long long int)(a-V[i][j].second)*abs(V[i][j].first-R);
				long long int t4 = (long long int)(V[i][j].second-1)*abs(V[i][j].first-R);
				ans[i] = ans[i]>s1?ans[i]:s1;
				ans[i] = ans[i]>s2?ans[i]:s2;
				ans[i] = ans[i]>s3?ans[i]:s3;
				ans[i] = ans[i]>s4?ans[i]:s4;
				ans[i] = ans[i]>t1?ans[i]:t1;
				ans[i] = ans[i]>t2?ans[i]:t2;
				ans[i] = ans[i]>t3?ans[i]:t3;
				ans[i] = ans[i]>t4?ans[i]:t4;
			}
		}
		
		for(int i=0;i<=9;i++) printf("%lld ",ans[i]);
		printf("\n");
	}
}