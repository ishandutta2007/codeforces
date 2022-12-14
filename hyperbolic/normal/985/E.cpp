#include <stdio.h>
#include <algorithm>

struct segTree{
	int value[2000010];
	void setValue(int ind ,int val, int l=1, int r=500001, int v=1)
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
	int getMax(int L, int R, int l=1, int r=500001, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
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
}T;

int x[500010],left[500010],right[500010],check[500010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int p = a;
	for(int i=a;i>=1;i--)
	{
		while(x[p]>x[i]+c) p--;
		if(p>=i+(b-1))
		{
			check[i] = 1;
			left[i] = i+(b-1);
			right[i] = p;
		}
		else check[i] = 0;
	}
	T.setValue(a+1,1);
	for(int i=a;i>=1;i--)
	{
		if(check[i]==0) T.setValue(i,0);
		else
		{
			
			int t = T.getMax(left[i]+1,right[i]+1);
			if(t==0) T.setValue(i,0);
			else T.setValue(i,1);
		}
	}
	int t = T.getMax(1,1);
	if(t==1) printf("YES");
	else printf("NO");
}