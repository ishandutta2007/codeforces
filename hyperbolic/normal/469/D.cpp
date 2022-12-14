#include <stdio.h>
#include <algorithm>
#include <map>
std::map<int,int> M;
int check[100010];
int main()
{
	int a,b,c,i,d,e,C=0;
	std::map<int,int> ::iterator it;
	scanf("%d%d%d",&a,&b,&c);
	for(i=1;i<=a;i++)
	{
		scanf("%d",&d);
		M[d]=i;
	}
	if(b>c)
	{
		C=1;
		d=b;
		b=c;
		c=d;
	}
	while(!M.empty())
	{
		it=M.end();
		it--;
		d=it->first;
		e=it->second;
		if(M.find(b-d)!=M.end())
		{
			check[e]=0;
			check[M[b-d]]=0;
			M.erase(d);
			M.erase(b-d);
			continue;
		}
		if(M.find(c-d)!=M.end())
		{
			check[e]=1;
			check[M[c-d]]=1;
			M.erase(d);
			M.erase(c-d);
			continue;
		}
		printf("NO");
		return 0;
	}
	printf("YES\n");
	if(C) for(i=1;i<=a;i++) printf("%d ",1-check[i]);
	else for(i=1;i<=a;i++) printf("%d ",check[i]);
}