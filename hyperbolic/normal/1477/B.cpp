#include <stdio.h>
#include <vector>

struct segTree{
	int value[800010];
	int lazy[800010];
	void setValue(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			value[v] = (r-l+1)*val;
			lazy[v] = val;
		}
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v], lazy[2*v] = lazy[v];
				value[2*v+1] = (r-h)*lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	int getValue(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1)*lazy[v], lazy[2*v] = lazy[v];
				value[2*v+1] = (r-h)*lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			int s1 = getValue(L,R,l,h,2*v);
			int s2 = getValue(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;
std::pair<int,int> P[200010];
char x[200010],y[200010],z[200010];
int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s%s",x+1,y+1);
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			P[i]=std::make_pair(c,d);
		}
		
		for(int i=1;i<=a;i++)
		{
			if(y[i]=='0') T.setValue(i,i,0);
			else T.setValue(i,i,1);
		}
		
		for(int i=b;i>=1;i--)
		{
			int l = (P[i].second-P[i].first+1);
			int c = T.getValue(P[i].first,P[i].second);
			int d = l - c;
			if(2*c<l) T.setValue(P[i].first,P[i].second,0);
			else if(2*d<l) T.setValue(P[i].first,P[i].second,1);
			else
			{
				printf("NO\n");
				goto u;
			}
		}
		
		for(int i=1;i<=a;i++) z[i] = '0'+T.getValue(i,i);
		for(int i=1;i<=a;i++)
		{
			if(x[i]!=z[i])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}