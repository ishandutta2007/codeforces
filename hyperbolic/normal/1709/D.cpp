#include <stdio.h>

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

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		T.setValue(i,c);
	}
	
	scanf("%d",&b);
	while(b--)
	{
		int c,d,e,f,g;
		scanf("%d%d%d%d%d",&c,&d,&e,&f,&g);
		if(c>e)
		{
			int temp = c;
			c = e;
			e = temp;
		}
		if(d>f)
		{
			int temp = d;
			d = f;
			f = temp;
		}
		
		if((e-c)%g!=0) printf("NO\n");
		else if((f-d)%g!=0) printf("NO\n");
		else
		{
			int limit = ((a-e)/g)*g+e;
			if(T.getMax(d,f)<limit) printf("YES\n");
			else printf("NO\n");
		}
	}
}