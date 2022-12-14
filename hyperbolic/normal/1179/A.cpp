#include <stdio.h>
#include <deque>
#include <vector>
int x[1000010];
std::pair<int,int> ans[2000010];
std::deque<int> D;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) D.push_back(x[i]);
	for(int i=1;i<=2*a;i++)
	{
		int A = D.front();
		D.pop_front();
		int B = D.front();
		D.pop_front();
		ans[i] = std::make_pair(A,B);
		if(A>B)
		{
			D.push_front(A);
			D.push_back(B);
		}
		else
		{
			D.push_front(B);
			D.push_back(A);
		}
	}
	
	for(int i=1;i<=b;i++)
	{
		long long int c;
		scanf("%lld",&c);
		if(c<=a) printf("%d %d\n",ans[c].first,ans[c].second);
		else
		{
			long long int k = (c-a)%(a-1)+a;
			printf("%d %d\n",ans[k].first,ans[k].second);
		}
	}
	
}