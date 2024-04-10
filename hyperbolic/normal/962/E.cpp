#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[5],temp1,temp2;

char x[5];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		scanf("%s",x+1);
		if(x[1]=='R') V[1].push_back(b);
		if(x[1]=='B') V[2].push_back(b);
		if(x[1]=='P') V[3].push_back(b);
	}
	std::sort(V[1].begin(),V[1].end());
	std::sort(V[2].begin(),V[2].end());
	std::sort(V[3].begin(),V[3].end());
	
	if(V[3].size()==0)
	{
		long long int sum = 0;
		if(V[1].size()>=2) sum += (V[1].back()-V[1][0]);
		if(V[2].size()>=2) sum += (V[2].back()-V[2][0]);
		printf("%lld",sum);
	}
	else
	{
		long long int ans = 0;
		int p1 = 0, p2 = 0, p3 = 0;
		if(p1<V[1].size()&&V[1][p1]<V[3][p3])
		{
			ans += V[3][p3] - V[1][p1];
			while(p1<V[1].size() && V[1][p1]<V[3][p3]) p1++;
		}
		if(p2<V[2].size()&&V[2][p2]<V[3][p3])
		{
			ans += V[3][p3] - V[2][p2];
			while(p2<V[2].size() && V[2][p2]<V[3][p3]) p2++;
		}
		
		for(int i=1;i<V[3].size();i++)
		{
			temp1.clear();
			temp2.clear();
			temp1.push_back(V[3][p3]);
			temp2.push_back(V[3][p3]);
			while(p1<V[1].size()&&V[1][p1]<V[3][i]) temp1.push_back(V[1][p1]),p1++;
			while(p2<V[2].size()&&V[2][p2]<V[3][i]) temp2.push_back(V[2][p2]),p2++;
			temp1.push_back(V[3][i]);
			temp2.push_back(V[3][i]);
			
			long long int M1 = 0, M2 = 0;
			for(int j=0;j+1<temp1.size();j++) M1 = M1>temp1[j+1]-temp1[j]?M1:temp1[j+1]-temp1[j];
			for(int j=0;j+1<temp2.size();j++) M2 = M2>temp2[j+1]-temp2[j]?M2:temp2[j+1]-temp2[j];
			long long int L = V[3][i]-V[3][p3];
			if(M1+M2>L) ans += (3*L-M1-M2);
			else ans += 2*L;
			p3 = i;
		}
		
		if(p1<V[1].size()) ans += V[1].back()-V[3][p3];
		if(p2<V[2].size()) ans += V[2].back()-V[3][p3];
		
		printf("%lld",ans);
	}
}