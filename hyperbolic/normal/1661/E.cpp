#include <stdio.h>

struct str{
	int left;
	int right;
	int leftCount;
	int rightCount;
	int value;
	int special;
}init[10];

str operator+(str a, str b)
{
	str ans;
	ans.left = a.left;
	ans.right = b.right;
	ans.leftCount = a.leftCount;
	ans.rightCount = b.rightCount;
	ans.value = a.value + b.value;
	ans.special = 0;
	
	int next[10] = {}, value[10] = {};
	for(int i=1;i<=6;i++) next[i] = i;
	if(((a.right>>0)&1)==1) value[1] = 1;
	if(((a.right>>1)&1)==1)
	{
		if(((a.right>>0)&1)==1) next[2] = 1, value[2] = 0;
		else value[2] = 1;
	}
	if(((a.right>>2)&1)==1)
	{
		if(((a.right>>1)&1)==1) next[3] = 2, value[3] = 0;
		else if(((a.right>>0)&1)==1 && a.rightCount==1) next[3] = 1, value[3] = 0;
		else value[3] = 1;
	}
	
	if(((b.left>>0)&1)==1) value[4] = 1;
	if(((b.left>>1)&1)==1)
	{
		if(((b.left>>0)&1)==1) next[5] = 4, value[5] = 0;
		else value[5] = 1;
	}
	if(((b.left>>2)&1)==1)
	{
		if(((b.left>>1)&1)==1) next[6] = 5, value[6] = 0;
		else if(((b.left>>0)&1)==1 && b.leftCount==1) next[6] = 4, value[6] = 0;
		else value[6] = 1;
	}
	
	int S = a.rightCount + b.leftCount;
	ans.value -= S;
	
	for(int i=0;i<=2;i++)
	{
		if(((a.right>>i)&1)==1 && ((b.left>>i)&1)==1)
		{
			int s = i+1, t = i+4;
			while(s!=next[s]) s = next[s];
			while(t!=next[t]) t = next[t];
			if(s!=t)
			{
				S -= value[t];
				next[t] = s;
			}
		}
	}
	ans.value += S;
	
	if(S==1)
	{
		if(a.special==1) ans.leftCount = 1;
		if(b.special==1) ans.rightCount = 1;
	}
	
	if(a.special==1&&b.special==1) ans.special = 1;
	return ans;
}

struct segTree{
	str value[2000010];
	void setValue(int ind, str val, int l=1, int r=500000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	
	str getValue(int L, int R, int l=1, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return init[0];
		else if(R<l) return init[0];
		else
		{
			int h = (l+r)/2;
			str A = getValue(L,R,l,h,2*v);
			str B = getValue(L,R,h+1,r,2*v+1);
			return A+B;
		}
	}
}T;

char x[4][500010];
int main()
{
	init[0] = {0,0,0,0,0,0};
	init[1] = {1,1,1,1,1,0};
	init[2] = {2,2,1,1,1,0};
	init[3] = {3,3,1,1,1,0};
	init[4] = {4,4,1,1,1,0};
	init[5] = {5,5,2,2,2,1};
	init[6] = {6,6,1,1,1,0};
	init[7] = {7,7,1,1,1,0};
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=3;i++) scanf("%s",x[i]+1);
	
	for(int j=1;j<=a;j++)
	{
		int val = (x[1][j]-'0')*4 + (x[2][j]-'0')*2 + (x[3][j]-'0');
		T.setValue(j,init[val]);
	}
	
	int b;
	scanf("%d",&b);
	while(b--)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		str A = T.getValue(c,d);
		printf("%d\n",A.value);
	}
}