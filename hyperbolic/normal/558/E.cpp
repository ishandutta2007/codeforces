#include <stdio.h>

struct segTree{
	int value[400010];
	int lazy[400010];
	
	void update(int k)
	{
		value[k] = value[2*k] + value[2*k+1];
	}
	void setValue(int L, int R, int val, int l=1, int r=100000, int v=1)
	{
		if(L>R) return;
		if(L<=l&&r<=R)
		{
			value[v] = val*(r-l+1);
			lazy[v] = val;
			return;
		}
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				lazy[2*v] = lazy[v], value[2*v] = (h-l+1)*lazy[v];
				lazy[2*v+1] = lazy[v], value[2*v+1] = (r-h)*lazy[v];
			}
			lazy[v] = -1;
			
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			update(v);
		}
	}
	int getSum(int L, int R, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				lazy[2*v] = lazy[v], value[2*v] = (h-l+1)*lazy[v];
				lazy[2*v+1] = lazy[v], value[2*v+1] = (r-h)*lazy[v];
			}
			lazy[v] = -1;
			
			return getSum(L,R,l,h,2*v) + getSum(L,R,h+1,r,2*v+1);
		}
	}
	
}T[30];


char x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) T[x[i]-'a'+1].setValue(i,i,1);
	
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		if(e==1) // increase
		{
			int start = c;
			for(int i=1;i<=26;i++)
			{
				int s = T[i].getSum(c,d);
				T[i].setValue(c,start-1,0);
				T[i].setValue(start,start+s-1,1);
				T[i].setValue(start+s,d,0);
				start += s;
			}
		}
		else
		{
			int start = c;
			for(int i=26;i>=1;i--)
			{
				int s = T[i].getSum(c,d);
				T[i].setValue(c,start-1,0);
				T[i].setValue(start,start+s-1,1);
				T[i].setValue(start+s,d,0);
				start += s;
			}
		}
		
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=26;j++)
		{
			if(T[j].getSum(i,i)==1)
			{
				printf("%c",'a'+j-1);
				break;
			}
		}
	}
}