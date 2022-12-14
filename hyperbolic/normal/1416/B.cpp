#include <stdio.h>
#include <vector>
struct str{
	int first;
	int second;
	int value;
};
std::vector<str> ans;
int x[10010];
void func(int s, int t, int val)
{
	ans.push_back({s,t,val});
	x[s] -= val*s;
	x[t] += val*s;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		if(sum%a!=0)
		{
			printf("-1\n");
			continue;
		}
		sum/=a;
		for(int i=2;i<=a;i++)
		{
			int t = (x[i]-(x[i]/i)*i);
			t = (i-t)%i;
			if(t>0) func(1,i,t);
			func(i,1,x[i]/i);
		}
		for(int i=2;i<=a;i++) func(1,i,sum);
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d %d\n",ans[i].first,ans[i].second,ans[i].value);
	}
}