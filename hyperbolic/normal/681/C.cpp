#include <iostream>
#include <string>
#include <queue>
#include <vector>
std::priority_queue<int, std::vector<int> , std::greater<int> > Q;
std::string ans[1000010];
int ans2[1000010];
int num = 1;
int main()
{
	int a,b;
	std::cin>>a;
	for(int i=1;i<=a;i++)
	{
		std::string S;
		std::cin>>S;
		if(S=="insert")
		{
			std::cin>>b;
			
			Q.push(b);
			ans[num] = "insert";
			ans2[num] = b;
			num++;
		}
		if(S=="getMin")
		{
			std::cin>>b;
			while(!Q.empty() && Q.top()<b)
			{
				ans[num] = "removeMin";
				num++;
				Q.pop();
			}
			if(Q.empty())
			{
				ans[num] = "insert";
				ans2[num] = b;
				Q.push(b);
				num++;
				
				ans[num] = "getMin";
				ans2[num] = b;
				num++;
			}
			else if(Q.top()==b)
			{
				ans[num] = "getMin";
				ans2[num] = b;
				num++;
			}
			else
			{
				ans[num] = "insert";
				ans2[num] = b;
				Q.push(b);
				num++;
				
				ans[num] = "getMin";
				ans2[num] = b;
				num++;
			}
		}
		if(S=="removeMin")
		{
			if(Q.empty())
			{
				ans[num] = "insert";
				ans2[num] = 1;
				num++;
				Q.push(1);
			}
			Q.pop();
			ans[num] = "removeMin";
			num++;
		}
	}
	std::cout<<num-1<<"\n";
	for(int i=1;i<num;i++)
	{
		if(ans[i]=="removeMin") std::cout<<ans[i]<<"\n";
		else std::cout<<ans[i]<<" "<<ans2[i]<<"\n";
	}
}