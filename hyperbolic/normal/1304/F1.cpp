#include <stdio.h>

struct segTree{
	int value[80010];
	int lazy[80010];
	void setValue(int ind, int val, int l=1, int r=20000, int v=1)
	{
		if(l==r) value[v] = val, lazy[v] = 0;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
			lazy[v] = 0;
		}
	}
	void addValue(int L, int R, int val, int l=1, int r=20000, int v=1)
	{
		if(L<=0) L = 1;
		if(R>20000) R = 20000;
		
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			value[2*v] += lazy[v], lazy[2*v] += lazy[v];
			value[2*v+1] += lazy[v], lazy[2*v+1] += lazy[v];
			lazy[v] = 0;
			
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMax(int L, int R, int l=1, int r=20000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			value[2*v] += lazy[v], lazy[2*v] += lazy[v];
			value[2*v+1] += lazy[v], lazy[2*v+1] += lazy[v];
			lazy[v] = 0;
			
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

int x[60][20010],y[60][20010];
int DP[60][20010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) y[i][j] = y[i][j-1] + x[i][j];
	
	for(int j=1;j<=b-c+1;j++) DP[a][j] = y[a][j+c-1] - y[a][j-1];
	for(int i=a-1;i>=1;i--)
	{
		for(int j=1;j<=b-c+1;j++) T.setValue(j,DP[i+1][j]);
		
		for(int j=1;j<=c;j++) T.addValue(j-c+1,j,-x[i+1][j]);
		int s = y[i][c] + y[i+1][c];
		DP[i][1] = s + T.getMax(1,b-c+1);
		
		for(int j=2;j<=b-c+1;j++)
		{
			s = (y[i][j+c-1]-y[i][j-1]) + (y[i+1][j+c-1]-y[i+1][j-1]);
			
			T.addValue(j-c,j-1,x[i+1][j-1]);
			T.addValue(j,j+c-1,-x[i+1][j+c-1]);
			DP[i][j] = s + T.getMax(1,b-c+1);
		}
	}
	
	
	
	int ans = 0;
	for(int i=1;i<=b-c+1;i++) ans = ans>DP[1][i]?ans:DP[1][i];
	printf("%d",ans);
	
}