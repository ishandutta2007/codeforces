#include <stdio.h>
#define MIN -123456789
struct segTree{
	int value[800010];
	void setValue(int ind ,int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return MIN;
		else if(R<l) return MIN;
		else
		{
			int h = (l+r)/2;
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T[32];

int x[200010][6];
int sign[3];
int main()
{
	sign[0] = 1, sign[1] = -1;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		for(int j=b+1;j<=5;j++) x[i][j] = 0;
		for(int k1=0;k1<=1;k1++)
		{
			for(int k2=0;k2<=1;k2++)
			{
				for(int k3=0;k3<=1;k3++)
				{
					for(int k4=0;k4<=1;k4++)
					{
						for(int k5=0;k5<=1;k5++)
						{
							int state = (1<<4)*k1 + (1<<3)*k2 + (1<<2)*k3 + (1<<1)*k4 + (1<<0)*k5;
							T[state].setValue(i,sign[k1]*x[i][1]+sign[k2]*x[i][2]+sign[k3]*x[i][3]+sign[k4]*x[i][4]+sign[k5]*x[i][5]);
						}
					}
				}
			}
		}
	}
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		if(d==1)
		{
			int e;
			scanf("%d",&e);
			for(int j=1;j<=b;j++) scanf("%d",&x[e][j]);
			for(int j=b+1;j<=5;j++) x[e][j] = 0;
			for(int k1=0;k1<=1;k1++)
			{
				for(int k2=0;k2<=1;k2++)
				{
					for(int k3=0;k3<=1;k3++)
					{
						for(int k4=0;k4<=1;k4++)
						{
							for(int k5=0;k5<=1;k5++)
							{
								int state = (1<<4)*k1 + (1<<3)*k2 + (1<<2)*k3 + (1<<1)*k4 + (1<<0)*k5;
								T[state].setValue(e,sign[k1]*x[e][1]+sign[k2]*x[e][2]+sign[k3]*x[e][3]+sign[k4]*x[e][4]+sign[k5]*x[e][5]);
							}
						}
					}
				}
			}
		}
		else
		{
			int e,f;
			scanf("%d%d",&e,&f);
			int ans = 0;
			for(int i=0;i<=31;i++)
			{
				int s1 = T[i].getMax(e,f);
				int s2 = T[31-i].getMax(e,f);
				ans = ans>s1+s2?ans:s1+s2;
			}
			printf("%d\n",ans);
		}
	}
}