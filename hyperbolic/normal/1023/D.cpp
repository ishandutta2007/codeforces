#include <stdio.h>

struct segTree{
	int value[1000010];
	void setValue(int left, int right, int val, int l=1, int r=200000, int v=1)
	{
		if(left<=l&&r<=right) value[v] = val;
		else if(r<left) return;
		else if(right<l) return;
		else
		{
			if(value[v]>0)
			{
				value[2*v] = value[v];
				value[2*v+1] = value[v];
				value[v] = 0;
			}
			
			int h = (l+r)/2;
			setValue(left,right,val,l,h,2*v);
			setValue(left,right,val,h+1,r,2*v+1);
		}
	}
	int getValue(int index, int l=1, int r=200000, int v=1)
	{
		if(value[v]>0) return value[v];
		if(l==r) return value[v];
		int h = (l+r)/2;
		if(index<=h) return getValue(index,l,h,2*v);
		else return getValue(index,h+1,r,2*v+1);
	}
}T;

int x[200010],y[200010];
int left[200010],right[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=a;i>=1;i--) left[x[i]] = i;
	for(int i=1;i<=a;i++) right[x[i]] = i;
	
	
	T.setValue(1,a,1);
	for(int i=2;i<=b;i++) if(left[i]>0) T.setValue(left[i],right[i],i);
	for(int i=1;i<=a;i++)
	{
		if(x[i]>0&&x[i]!=T.getValue(i))
		{
			printf("NO");
			return 0;
		}
	}
	if(left[b]==0)
	{
		for(int i=1;i<=a;i++)
		{
			if(x[i]==0)
			{
				T.setValue(i,i,b);
				break;
			}
		}
	}
	for(int i=1;i<=a;i++) y[i] = T.getValue(i);
	
	int control = 0;
	for(int i=1;i<=a;i++) if(y[i]==b) control = 1;
	
	if(control==0)
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=a;i++) printf("%d ",y[i]);
}