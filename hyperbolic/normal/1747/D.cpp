#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

int x[200010],s[200010];
std::vector<int> index;
std::map<int,int> hash;
std::set<int> S[3][200010];
int count0[200010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) s[i] = s[i-1]^x[i];
	for(int i=0;i<=a;i++) index.push_back(s[i]);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i;
	for(int i=0;i<=a;i++) S[i%2][hash[s[i]]].insert(i);
	
	for(int i=1;i<=a;i++) if(x[i]==0) count0[i] = 1;
	for(int i=1;i<=a;i++) count0[i] += count0[i-1];
	
	while(b--)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if((s[d]^s[c-1])!=0)
		{
			printf("-1\n");
			continue;
		}
		
		if(count0[d]-count0[c-1]==d-c+1)
		{
			printf("0\n");
			continue;
		}
		
		if((d-c+1)%2==1)
		{
			printf("1\n");
			continue;
		}
		
		if(x[d]==0 || x[c]==0)
		{
			printf("1\n");
			continue;
		}
		
		std::set<int> ::iterator it = S[c%2][hash[s[c-1]]].lower_bound(c);
		if(it==S[c%2][hash[s[c-1]]].end()) printf("-1\n");
		else if((*it)>d) printf("-1\n");
		else printf("2\n");
	}
}