#include <stdio.h>
#include <vector>

long long int MIN = -1;
struct str{
	long long int oddMax;
	long long int oddMin;
	long long int evenMax;
	long long int evenMin;
};
struct segTree{
	long long int oddMax[1200010];
	long long int oddMin[1200010];
	long long int evenMax[1200010];
	long long int evenMin[1200010];
	void setValue(int ind, int val, int l=1, int r=300000, int v=1)
	{
		if(l==r)
		{
			oddMax[v] = oddMin[v] = val;
			evenMax[v] = evenMin[v] = 0;
			return;
		}
		int h = (l+r)/2;
		if(ind<=h) setValue(ind,val,l,h,2*v);
		else setValue(ind,val,h+1,r,2*v+1);
		oddMax[v] = evenMax[2*v]+oddMax[2*v+1]>oddMax[2*v]-evenMin[2*v+1]?evenMax[2*v]+oddMax[2*v+1]:oddMax[2*v]-evenMin[2*v+1];
		oddMin[v] = evenMin[2*v]+oddMin[2*v+1]<oddMin[2*v]-evenMax[2*v+1]?evenMin[2*v]+oddMin[2*v+1]:oddMin[2*v]-evenMax[2*v+1];
		evenMax[v] = evenMax[2*v]+evenMax[2*v+1]>oddMax[2*v]-oddMin[2*v+1]?evenMax[2*v]+evenMax[2*v+1]:oddMax[2*v]-oddMin[2*v+1];
		evenMin[v] = evenMin[2*v]+evenMin[2*v+1]<oddMin[2*v]-oddMax[2*v+1]?evenMin[2*v]+evenMin[2*v+1]:oddMin[2*v]-oddMax[2*v+1];
	}
	str getMax(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return {oddMax[v],oddMin[v],evenMax[v],evenMin[v]};
		else if(r<L) return {MIN,MIN,MIN,MIN};
		else if(R<l) return {MIN,MIN,MIN,MIN};
		else
		{
			int h = (l+r)/2;
			str P1 = getMax(L,R,l,h,2*v);
			str P2 = getMax(L,R,h+1,r,2*v+1);
			str P;
			if(P1.oddMax==MIN) return P2;
			else if(P2.oddMax==MIN) return P1;
			else
			{
				P.oddMax = P1.evenMax + P2.oddMax > P1.oddMax - P2.evenMin? P1.evenMax + P2.oddMax : P1.oddMax - P2.evenMin;
				P.oddMin = P1.evenMin + P2.oddMin < P1.oddMin - P2.evenMax? P1.evenMin + P2.oddMin : P1.oddMin - P2.evenMax;
				P.evenMax = P1.evenMax + P2.evenMax > P1.oddMax - P2.oddMin? P1.evenMax + P2.evenMax : P1.oddMax - P2.oddMin;
				P.evenMin = P1.evenMin + P2.evenMin < P1.oddMin - P2.oddMax? P1.evenMin + P2.evenMin : P1.oddMin - P2.oddMax;
				return P;
			}
		}
	}
}T;
long long int func(int L, int R)
{
	str P = T.getMax(L,R);
	return P.oddMax>P.evenMax?P.oddMax:P.evenMax;
}

int x[300010];
int main()
{
	for(int i=1;i<=13;i++) MIN*=10;
	
	int W;
	scanf("%d",&W);
	while(W--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) T.setValue(i,x[i]);
		printf("%lld\n",func(1,a));
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			T.setValue(c,x[d]);
			T.setValue(d,x[c]);
			int temp = x[c];
			x[c] = x[d];
			x[d] = temp;
			printf("%lld\n",func(1,a));
		}
	}
}