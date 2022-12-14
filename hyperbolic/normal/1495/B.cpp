#include <stdio.h>

struct segTree{
	int value[400010];
	void setValue(int ind ,int val, int l=1, int r=100000, int v=1)
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
	int getMax(int L, int R, int l=1, int r=100000, int v=1)
	{
		if(L<=l&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}TL1,TL2,TL3,TL4,TR1,TR2,TR3,TR4;

int x[100010],left1[100010],right1[100010],left2[100010],right2[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	left1[1] = left2[1] = 1;
	for(int i=2;i<=a;i++)
	{
		if(x[i-1]<x[i])
		{
			left1[i] = left1[i-1]+1;
			left2[i] = 1;
		}
		else
		{
			left1[i] = 1;
			left2[i] = left2[i-1]+1;
		}
	}
	right1[a] = right2[a] = 1;
	for(int i=a-1;i>=1;i--)
	{
		if(x[i+1]<x[i])
		{
			right1[i] = right1[i+1]+1;
			right2[i] = 1;
		}
		else
		{
			right1[i] = 1;
			right2[i] = right2[i+1]+1;
		}
	}
	
	for(int i=1;i<=a;i++) TL1.setValue(i,left1[i]);
	for(int i=1;i<=a;i++) TL2.setValue(i,left2[i]);
	for(int i=1;i<=a;i++) TR1.setValue(i,right1[i]);
	for(int i=1;i<=a;i++) TR2.setValue(i,right2[i]);
	for(int i=1;i<=a;i+=2) TR3.setValue(i,right2[i]);
	for(int i=2;i<=a;i+=2) TR4.setValue(i,right2[i]);
	for(int i=1;i<=a;i+=2) TL3.setValue(i,left2[i]);
	for(int i=2;i<=a;i+=2) TL4.setValue(i,left2[i]);
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int limit = left1[i]>right1[i]?left1[i]:right1[i];
		int L = i-left1[i];
		int R = i+right1[i];
		if(TR2.getMax(i+1,a)>=limit) continue;
		if(TL2.getMax(R,a)>=limit) continue;
		if(TL2.getMax(1,i-1)>=limit) continue;
		if(TR2.getMax(1,L)>=limit) continue;
		if(i%2==0)
		{
			if(TR3.getMax(i+1,R-1)>=left1[i]) continue;
			if(TL3.getMax(i+1,R-1)>=left1[i]) continue;
			if(TL3.getMax(L+1,i-1)>=right1[i]) continue;
			if(TR3.getMax(L+1,i-1)>=right1[i]) continue;
		}
		else
		{
			if(TR4.getMax(i+1,R-1)>=left1[i]) continue;
			if(TL4.getMax(i+1,R-1)>=left1[i]) continue;
			if(TL4.getMax(L+1,i-1)>=right1[i]) continue;
			if(TR4.getMax(L+1,i-1)>=right1[i]) continue;
		}
		
		//printf("%d!!\n",i);
		ans++;
	}
	printf("%d\n",ans);
}