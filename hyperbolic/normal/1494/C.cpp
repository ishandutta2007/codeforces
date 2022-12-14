#include <stdio.h>
#include <map>
#include <deque>
#define MAX 1234567890
#define MIN -1234567890
std::map<int,int> M;
int x[200010],y[200010];
std::deque<int> D;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		x[0] = MIN, x[a+1] = MAX;
		for(int i=1;i<=b;i++) scanf("%d",&y[i]);
		for(int i=1;i<=b;i++) M[y[i]] = 1;
		
		int p1 = a+1, p2 = b+1;
		for(int i=1;i<=a;i++)
		{
			if(x[i]>0)
			{
				p1 = i;
				break;
			}
		}
		for(int i=1;i<=b;i++)
		{
			if(y[i]>0)
			{
				p2 = i;
				break;
			}
		}
		int ans1 = 0, ans2 = 0;
		
		D.clear();
		int pivot = a;
		int limit = a-p1+1;
		int count1 = 0, count2 = 0;
		for(int i=b;i>=p2;i--)
		{
			D.push_back(y[i]);
			while(1)
			{
				int control = 0;
				while(!D.empty() && D.front()-D.back()>=limit) control = 1, D.pop_front();
				while(!D.empty() && pivot>=p1 && D.front()<x[pivot])
				{
					control = 1;
					if(M[x[pivot]]==1) count1++;
					pivot--,limit--;
				}
				if(control==0) break;
			}
			
			int t = D.size();
			ans1 = ans1>t+count1? ans1: t+count1;
		}
		
		D.clear();
		pivot = 1;
		limit = p1-1;
		for(int i=1;i<p2;i++)
		{
			D.push_back(y[i]);
			while(1)
			{
				int control = 0;
				while(!D.empty() && D.back()-D.front()>=limit) control = 1, D.pop_front();
				while(!D.empty() && pivot<p1 && D.front()>x[pivot])
				{
					control = 1;
					if(M[x[pivot]]==1) count2++;
					pivot++,limit--;
				}
				if(control==0) break;
			}
			
			int t = D.size();
			ans2 = ans2>t+count2? ans2: t+count2;
		}
		//printf("%d %d!!\n",ans1,ans2);
		printf("%d\n",ans1+ans2);
	}
}