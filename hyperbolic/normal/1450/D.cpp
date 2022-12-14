#include <stdio.h>
#include <vector>

struct segTree{
	int value[1200010];
	void setValue(int ind ,int val, int l=0, int r=300001, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int left(int L, int R, int val, int l=0, int r=300001, int v=1)
	{
		if(L<=l&&r<=R)
		{
			if(value[v]>=val) return l-1;
			else if(l==r) return l;
			else
			{
				int h = (l+r)/2;
				int t = left(L,R,val,h+1,r,2*v+1);
				
				if(t!=h) return t;
				else return left(L,R,val,l,h,2*v);
			}
		}
		else if(r<L) return l-1;
		else if(R<l) return l-1;
		else
		{
			int h = (l+r)/2;
			int t = left(L,R,val,h+1,r,2*v+1);
			
			if(t!=h) return t;
			else return left(L,R,val,l,h,2*v);
		}
	}
	
	int right(int L, int R, int val, int l=0, int r=300001, int v=1)
	{
		if(L<=l&&r<=R)
		{
			if(value[v]>=val) return r+1;
			else if(l==r) return r;
			else
			{
				int h = (l+r)/2;
				int t = right(L,R,val,l,h,2*v);
				
				if(t!=h+1) return t;
				else return right(L,R,val,h+1,r,2*v+1);
			}
		}
		else if(r<L) return r+1;
		else if(R<l) return r+1;
		else
		{
			int h = (l+r)/2;
			int t = right(L,R,val,l,h,2*v);
			
			if(t!=h+1) return t;
			else return right(L,R,val,h+1,r,2*v+1);
		}
	}
}T;

int ans[300010],x[300010];
int limitL[300010],limitR[300010];
std::vector<int> V[300010];

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a+1;i++) limitL[i] = 0, limitR[i] = a+1;
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) T.setValue(i,x[i]);
		T.setValue(0,0);
		T.setValue(a+1,0);
		x[0] = 0;
		x[a+1] = 0;
		
		for(int i=1;i<=a;i++) V[x[i]].push_back(i);
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()>0)
			{
				int s = V[i][0];
				int t = V[i].back();
				int L = T.left(0,t,i);
				int R = T.right(s,a+1,i);
				//printf("%d %d %d %d??\n",s,t,L,R);
				limitL[i] = (t-s+1);
				limitR[i] = (R-L-1);
			}
			else limitL[i] = a+1, limitR[i] = 0;
		}
		
		for(int i=1;i<=a;i++)
		{
			limitL[i] = limitL[i-1]>limitL[i]?limitL[i-1]:limitL[i];
			limitR[i] = limitR[i-1]<limitR[i]?limitR[i-1]:limitR[i];
		}
		for(int i=1;i<=a;i++)
		{
			if(limitL[i]<=a-i+1&&a-i+1<=limitR[i]) ans[a-i+1] = 1;
			else ans[a-i+1] = 0;
		}
		
		for(int i=1;i<=a;i++) printf("%d",ans[i]);
		printf("\n");
	}
}