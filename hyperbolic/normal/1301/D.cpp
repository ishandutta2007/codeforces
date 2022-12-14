#include <stdio.h>
#include <vector>

std::vector< std::pair<int,char> > ans;
void print()
{
	printf("YES\n");
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i].second=='!') printf("%d DU\n",ans[i].first);
		else if(ans[i].second=='@') printf("%d DUL\n",ans[i].first);
		else printf("%d %c\n",ans[i].first,ans[i].second);
	}
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int s = 0;
	for(int i=1;i<a;i++)
	{
		if(s+(b-1)>=c)
		{
			ans.push_back(std::make_pair(c-s,'R'));
			goto u;
		}
		else if(b>1) ans.push_back(std::make_pair(b-1,'R')), s+=(b-1);
		for(int j=b;j>=2;j--)
		{
			if(s+1==c)
			{
				ans.push_back(std::make_pair(1,'D'));
				goto u;
			}
			else if(s+2==c)
			{
				ans.push_back(std::make_pair(1,'!'));
				goto u;
			}
			else if(s+3==c)
			{
				if(ans[ans.size()-1].second=='@') ans[ans.size()-1].first++;
				else ans.push_back(std::make_pair(1,'@'));
				goto u;
			}
			else
			{
				if(ans[ans.size()-1].second=='@') ans[ans.size()-1].first++;
				else ans.push_back(std::make_pair(1,'@'));
				s+=3;
			}
		}
		if(s+1==c)
		{
			ans.push_back(std::make_pair(1,'D'));
			goto u;
		}
		else ans.push_back(std::make_pair(1,'D')),s++;
		
		continue;
		u:;
		print();
		return 0;
	}
	
	if(s+(b-1)>=c)
	{
		ans.push_back(std::make_pair(c-s,'R'));
		print();
		return 0;
	}
	else if(b>1) ans.push_back(std::make_pair(b-1,'R')), s+=(b-1);
	
	if(s+(b-1)>=c)
	{
		ans.push_back(std::make_pair(c-s,'L'));
		print();
		return 0;
	}
	else if(b>1) ans.push_back(std::make_pair(b-1,'L')), s+=(b-1);
	if(s+(a-1)>=c)
	{
		ans.push_back(std::make_pair(c-s,'U'));
		print();
	}
	else printf("NO");
}