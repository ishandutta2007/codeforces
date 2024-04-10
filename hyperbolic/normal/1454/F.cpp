#include <stdio.h>
#define MAX 1234567890
struct segTree{
	int value[800010];
	int setValue(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T2,T3;

int x[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) T2.setValue(i,x[i]);
		for(int i=1;i<=a;i++) T3.setValue(i,-x[i]);
		
		int p = a;
		int max1 = 0,max2=0;
		for(int i=1;i<=a;i++)
		{
			max1 = max1>x[i]?max1:x[i];
			while(p>i&&x[p]<=max1)
			{
				max2 = max2>x[p]?max2:x[p];
				p--;
			}
			
			if(max1!=max2) continue;
			
			if(p!=a&&i+1<=p&&T2.getMin(i+1,p)==max1)
			{
				printf("YES\n");
				printf("%d %d %d\n",i,p-(i+1)+1,a-p);
				goto u;
			}
			if(p==a) continue;
			
			p++;
			if(p!=a&&i+1<=p&&T2.getMin(i+1,p)==max1&&T3.getMin(p+1,a)==-max1)
			{
				printf("YES\n");
				printf("%d %d %d\n",i,p-(i+1)+1,a-p);
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}