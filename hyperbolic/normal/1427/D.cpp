#include <stdio.h>
#include <vector>
int a;
int x[110],y[110];
std::vector<int> temp;
std::vector< std::vector<int> > ans;

void suffle()
{
	int sum = 0;
	for(int i=0;i<temp.size();i++)
	{
		int L = sum+1;
		int R = sum+temp[i];
		int L2 = a-(sum+temp[i])+1;
		int R2 = a-(sum+1)+1;
		sum += temp[i];
		for(int j=L;j<=R;j++) y[L2-L+j] = x[j];
	}
	for(int i=1;i<=a;i++) x[i] = y[i];
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int L = 1, R = a;
	for(int i=1;i<a;i++)
	{
		temp.clear();
		int p;
		if((a-i)%2==0)
		{
			//1...i-1 is in
			for(int j=1;j<i;j++) temp.push_back(1);
			for(int j=i;j<=a;j++) if(x[j]==i) p = j;
			if(p-i+1>=1) temp.push_back(p-i+1);
			if(a-p>=1) temp.push_back(a-p);
		}
		else
		{
			for(int j=1;j<=a-i+1;j++) if(x[j]==i) p = j;
			if(p-1>=1) temp.push_back(p-1);
			if(a-i+1-p+1>=1) temp.push_back(a-i+1-p+1);
			for(int j=1;j<i;j++) temp.push_back(1);
		}
		if(temp.size()==1) continue;
		suffle();
		ans.push_back(temp);
	}
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d ",ans[i].size());
		for(int j=0;j<ans[i].size();j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
}