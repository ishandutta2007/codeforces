#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#define MOD 99999971

int x[1510][1510],y[1510][1510],z[1510][1510];
std::map<long long int,int> M;
std::vector<int> ans;
std::vector< std::pair<int,int> > save,save2;
int check[1510];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&y[i][j]);
	
	int control = 0;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i]!=x[j]) control = 1;
	if(control==0)
	{
		printf("0\n");
		return 0;
	}
	
	for(int i=1;i<=a;i++)
	{
		long long int sum = 0;
		for(int j=1;j<=b;j++) sum *= MOD, sum += x[i][j];
		if(M[sum]!=0) continue;
		M[sum] = i;
	}
	for(int i=1;i<=a;i++)
	{
		long long int sum = 0;
		for(int j=1;j<=b;j++) sum *= MOD, sum += y[i][j];
		if(M[sum]==0)
		{
			printf("-1");
			return 0;
		}
		y[i][0] = M[sum];
	}
	
	for(int j=0;j<=b;j++) for(int i=2;i<=a;i++) if(y[i-1][j]>y[i][j]) z[i][j] = 1;
	for(int j=0;j<=b;j++) for(int i=2;i<=a;i++) z[i][j] += z[i-1][j];
	
	save.push_back({1,a});
	while(1)
	{
		for(int j=0;j<=b;j++)
		{
			if(check[j]) continue;
			for(int i=0;i<save.size();i++)
			{
				int L = save[i].first;
				int R = save[i].second;
				if(z[R][j]-z[L][j]>0) goto u;
			}
			if(j==0)
			{
				if(ans.size()==0)
				{
					printf("0\n");
					return 0;
				}
				else
				{
					printf("%d\n",ans.size());
					for(int k=ans.size()-1;k>=0;k--) printf("%d ",ans[k]);
					return 0;
				}
			}
			
			ans.push_back(j);
			check[j] = 1;
			save2.clear();
			
			for(int i=0;i<save.size();i++)
			{
				int L = save[i].first;
				int R = save[i].second;
				int start = L;
				for(int k=L;k<=R;k++)
				{
					if(y[k][j]==y[start][j]);
					else
					{
						if(start!=k-1) save2.push_back({start,k-1});
						start = k;
					}
				}
				if(start!=R) save2.push_back({start,R});
			}
			save.clear();
			save = save2;
			goto v;
			
			u:;
		}
		printf("-1");
		return 0;
		v:;
	}
}