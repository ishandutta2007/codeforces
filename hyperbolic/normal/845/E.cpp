#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> index1, index2;
std::map<int,int> hash1, hash2;
int sum[3010][3010];
std::pair<int,int> x[510];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		x[i] = std::make_pair(d,e);
	}
	
	int min = 0, max = 1000000000;
	int ans = max;
	while(min<=max)
	{
		index1.clear();
		index2.clear();
		hash1.clear();
		hash2.clear();
		int h = (min+max)/2;
		for(int i=1;i<=c;i++)
		{
			int L = x[i].first-h>1?x[i].first-h:1;
			int R = x[i].first+h<a?x[i].first+h:a;
			int D = x[i].second-h>1?x[i].second-h:1;
			int U = x[i].second+h<b?x[i].second+h:b;
			index1.push_back(L);
			if(L-1>=1) index1.push_back(L-1);
			if(L+1<=a) index1.push_back(L+1);
			index1.push_back(R);
			if(R-1>=1) index1.push_back(R-1);
			if(R+1<=a) index1.push_back(R+1);
			index2.push_back(U);
			if(U-1>=1) index2.push_back(U-1);
			if(U+1<=b) index2.push_back(U+1);
			index2.push_back(D);
			if(D-1>=1) index2.push_back(D-1);
			if(D+1<=b) index2.push_back(D+1);
		}
		
		index1.push_back(1),index1.push_back(a);
		index2.push_back(1),index2.push_back(b);
		std::sort(index1.begin(),index1.end());
		index1.erase(std::unique(index1.begin(),index1.end()),index1.end());
		for(int i=0;i<index1.size();i++) hash1[index1[i]] = i+1;
		std::sort(index2.begin(),index2.end());
		index2.erase(std::unique(index2.begin(),index2.end()),index2.end());
		for(int i=0;i<index2.size();i++) hash2[index2[i]] = i+1;
		
		
		for(int i=1;i<=index1.size();i++) for(int j=1;j<=index2.size();j++) sum[i][j] = 0;
		for(int i=1;i<=c;i++)
		{
			int L = hash1[x[i].first-h>1?x[i].first-h:1];
			int R = hash1[x[i].first+h<a?x[i].first+h:a];
			int D = hash2[x[i].second-h>1?x[i].second-h:1];
			int U = hash2[x[i].second+h<b?x[i].second+h:b];
			for(int j=L;j<=R;j++) sum[j][D]++, sum[j][U+1]--;
		}
		int limit1 = -1, limit2 = -1, limit3 = -1, limit4 = -1;
		for(int i=1;i<=index1.size();i++)
		{
			for(int j=1;j<=index2.size();j++)
			{
				sum[i][j] += sum[i][j-1];
				if(sum[i][j]==0)
				{
					if(limit1==-1) limit1 = index1[i-1];
					else limit1 = limit1<index1[i-1]?limit1:index1[i-1];
					if(limit2==-1) limit2 = index1[i-1];
					else limit2 = limit2>index1[i-1]?limit2:index1[i-1];
					if(limit3==-1) limit3 = index2[j-1];
					else limit3 = limit3<index2[j-1]?limit3:index2[j-1];
					if(limit4==-1) limit4 = index2[j-1];
					else limit4 = limit4>index2[j-1]?limit4:index2[j-1];
				}
			}
		}
		
		if(limit1==-1)
		{
			ans = h;
			max = h-1;
		}
		else if((limit2-limit1)<=2*h && (limit4-limit3)<=2*h)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
	}
	printf("%d",ans);
}