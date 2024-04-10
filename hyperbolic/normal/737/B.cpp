#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > event;
int count[400010];
char x[400010];
int y[400010];
std::vector<int> ans;

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) y[i] = x[i]-'0';
	for(int i=1;i<=a;i++) y[i] += y[i-1];
	
	for(int i=a;i>=a-c+2;i--) count[i] = 0;
	for(int i=a-c+1;i>=1;i--)
	{
		int s = y[i+c-1] - y[i-1];
		if(s==0) count[i] = count[i+c] + 1;
		else count[i] = count[i+1];
	}
	
	int p = 1;
	for(int i=1;i<=a+1;i++) if(x[i]!='0') event.push_back(std::make_pair(p,i-1)), p = i+1;
	
	int sum = 0;
	for(int i=0;i<event.size();i++)
	{
		for(int j = event[i].first + c - 1; j<=event[i].second;j+=c)
		{
			ans.push_back(j);
			if(count[j+1]+sum<b) goto u;
		}
	}
	u:;
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}