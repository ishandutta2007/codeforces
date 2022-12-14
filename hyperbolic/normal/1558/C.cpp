#include <stdio.h>
#include <vector>

int x[3010],temp[3010];
std::vector<int> V1,V2,ans;
void func(int k)
{
	ans.push_back(2*k+1);
	int L = 0, R = k;
	for(int i=L;i<=R;i++) temp[i] = V1[i];
	for(int i=L;i<=R;i++) V1[i] = temp[L+R-i];
	if(k>0)
	{
		L = 0, R = k-1;
		for(int i=L;i<=R;i++) temp[i] = V2[i];
		for(int i=L;i<=R;i++) V2[i] = temp[L+R-i];
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		V1.clear();
		V2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i+=2) V1.push_back(x[i]);
		for(int i=2;i<=a;i+=2) V2.push_back(x[i]);
		
		for(int i=0;i<V1.size();i++)
		{
			int val = a-2*i;
			if(val==1) break;
			
			int p = -1;
			int t = (int)V1.size()-i-1;
			for(int j=0;j<V1.size();j++) if(V1[j]==val) p = j;
			if(p==-1)
			{
				printf("-1\n");
				goto u;
			}
			
			int p2 = -1;
			for(int j=0;j<V2.size();j++) if(V2[j]==val-1) p2 = j;
			if(p2==-1)
			{
				printf("-1\n");
				goto u;
			}
			
			func(p);
			for(int j=0;j<V1.size();j++) if(V1[j]==val) p = j;
			for(int j=0;j<V2.size();j++) if(V2[j]==val-1) p2 = j;
				
			func(p2);
			func(p2+1);
			func(1);
			func(t);
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
		u:;
	}
}