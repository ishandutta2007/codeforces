#include <stdio.h>
#include <vector>

std::pair<int,int> P[200010];
long long int length[200010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	a*=-1;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&P[i].first,&P[i].second);
	for(int i=1;i<=n;i++) length[i] = length[i-1] + (P[i].second-P[i].first);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		int min = 1, max = n;
		int right = -1;
		while(min<=max)
		{
			int h = (min+max)/2;
			double coor = d + (double)(P[h].first-d)*(a+e)/e;
			if(c <= coor) max = h-1;
			else
			{
				right = h;
				min = h+1;
			}
		}
		
		min = 1, max = n;
		int left = -1;
		while(min<=max)
		{
			int h = (min+max)/2;
			double coor = d + (double)(P[h].second-d)*(a+e)/e;
			if(coor <= b ) min = h+1;
			else
			{
				left = h;
				max = h-1;
			}
		}
		//printf("%d %d!!!\n",left,right);
		if(left==-1||right==-1) printf("%.12lf\n",0);
		else if(left>right) printf("%.12lf\n",0);
		else if(left==right)
		{
			double L = d + (double)(P[left].first-d)*(a+e)/e;
			double R = d + (double)(P[right].second-d)*(a+e)/e;
			L = L>b?L:b;
			R = R<c?R:c;
			printf("%.12lf\n",R-L);
		}
		else
		{
			double L1 = d + (double)(P[left].first-d)*(a+e)/e;
			double R1 = d + (double)(P[left].second-d)*(a+e)/e;
			double L2 = d + (double)(P[right].first-d)*(a+e)/e;
			double R2 = d + (double)(P[right].second-d)*(a+e)/e;
			L1 = L1>b?L1:b;
			R1 = R1<c?R1:c;
			L2 = L2>b?L2:b;
			R2 = R2<c?R2:c;
			if(left+1<=right-1)
			{
				double K = (double)(length[right-1]-length[left])*(a+e)/e;
				printf("%.12lf\n",R1-L1+R2-L2+K);
			}
			else printf("%.12lf\n",R1-L1+R2-L2);
		}
	}
}