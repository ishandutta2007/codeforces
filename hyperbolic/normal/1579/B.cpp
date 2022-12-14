#include <stdio.h>
#include <vector>

struct str{
	int first;
	int second;
	int value;
};
std::vector<str> ans;

int x[110],temp[110];
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
		
		for(int i=1;i<=a;i++)
		{
			int L = i, R = a;
			int p = L;
			for(int j=L+1;j<=R;j++) if(x[j]<x[p]) p = j;
			if(p==i) continue;
			
			ans.push_back({L,R,p-i});
			for(int j=L;j<=R;j++) temp[L + (j-L - (p-i) + (R-L+1))%(R-L+1)] = x[j];
			for(int j=L;j<=R;j++) x[j] = temp[j];
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d %d\n",ans[i].first,ans[i].second,ans[i].value);
	}
}