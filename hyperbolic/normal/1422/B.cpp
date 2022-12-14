#include <stdio.h>
#include <algorithm>
#include <vector>

int x[110][110];
std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		
		long long int ans = 0;
		for(int i=1;i<=(a+1)/2;i++)
		{
			for(int j=1;j<=(b+1)/2;j++)
			{
				V.clear();
				int i2 = a-i+1, j2 = j;
				int i3 = i, j3 = b-j+1;
				int i4 = a-i+1, j4 = b-j+1;
				V.push_back(x[i][j]);
				V.push_back(x[i2][j2]);
				V.push_back(x[i3][j3]);
				V.push_back(x[i4][j4]);
				std::sort(V.begin(),V.end());
				long long int S = (V[3]-V[0]) + (V[2]-V[1]);
				if(a%2==1 && i==(a+1)/2) S/=2;
				else if(b%2==1 && j==(b+1)/2) S/=2;
				ans += S;
			}
		}
		printf("%lld\n",ans);
	}
}