#include <stdio.h>
#include <vector>

int start;
std::vector< std::pair<int,int> > edge;
int makePath(int root, int end, int len)
{
	if(len==1)
	{
		edge.push_back(std::make_pair(root,end));
		return start;
	}
	
	int p = root;
	for(int i=1;i<len;i++)
	{
		edge.push_back(std::make_pair(p,start));
		p = start;
		start++;
	}
	edge.push_back(std::make_pair(start-1,end));
	return start;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		edge.clear();
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		
		int root;
		start = 4;
		if(b+c==d)
		{
			root = 2;
			start = makePath(2,1,b);
			start = makePath(2,3,c);
			for(int i=start;i<=a;i++) edge.push_back(std::make_pair(i,root));
		}
		else if(b+d==c)
		{
			root = 1;
			start = makePath(1,2,b);
			start = makePath(1,3,d);
			for(int i=start;i<=a;i++) edge.push_back(std::make_pair(i,root));
		}
		else if(c+d==b)
		{
			root = 3;
			start = makePath(3,1,d);
			start = makePath(3,2,c);
			for(int i=start;i<=a;i++) edge.push_back(std::make_pair(i,root));
		}
		else if((b+c+d)%2==0 && b+c > d && b+d > c && c+d > b && (b+c+d)/2+1 <= a)
		{
			root = 4;
			start = 5;
			start = makePath(root,1,(b+d-c)/2);
			start = makePath(root,2,(b+c-d)/2);
			start = makePath(root,3,(c+d-b)/2);
			for(int i=start;i<=a;i++) edge.push_back(std::make_pair(i,root));
		}
		else
		{
			printf("NO\n");
			continue;
		}
		
		printf("YES\n");
		for(int i=0;i<edge.size();i++) printf("%d %d\n",edge[i].first,edge[i].second);
	}
}