#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int x0;
	int y0;
	int z0;
};
bool cmp(str a, str b)
{
	return a.z0<b.z0;
}

bool cmp2(str a, str b)
{
	return a.y0<b.y0;
}

std::vector<str> V1,V2,V3;

struct segTree{
	int value[80010];
	void update(int k)
	{
		value[k] = value[2*k] + value[2*k+1];
	}
	void set(int ind, int val, int l=0,int r=10000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) set(ind,val,l,h,2*v);
			else set(ind,val,h+1,r,2*v+1);
			update(v);
		}
	}
	int sum(int L, int R, int l=0, int r=10000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			return sum(L,R,l,h,2*v)+sum(L,R,h+1,r,2*v+1);
		}
	}
}T;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		b+=5000, c+=5000, d+=5000, e+=5000;
		if(b==d)
		{
			if(c<e) V1.push_back({c,e,b});
			else V1.push_back({e,c,b});
		}
		else
		{
			if(b<d) V2.push_back({b,d,c});
			else V2.push_back({d,b,c});
		}
	}
	std::sort(V1.begin(),V1.end(),cmp);
	
	long long int ans = 0;
	for(int i=0;i<V1.size();i++)
	{
		V3.clear();
		for(int j=0;j<V2.size();j++)
		{
			if(V2[j].x0<=V1[i].z0 && V1[i].x0<=V2[j].z0 && V2[j].z0 <= V1[i].y0) V3.push_back(V2[j]);
		}
		std::sort(V3.begin(),V3.end(),cmp2);
		
		int p = V3.size()-1;
		for(int j=V1.size()-1;j>i;j--)
		{
			while(p>=0)
			{
				if(V3[p].y0<V1[j].z0) break;
				else T.set(V3[p].z0,1);
				p--;
			}
			
			int L = V1[i].x0>V1[j].x0?V1[i].x0:V1[j].x0;
			int R = V1[i].y0<V1[j].y0?V1[i].y0:V1[j].y0;
			if(L<=R)
			{
				long long int t = T.sum(L,R);
				ans += t*(t-1)/2;
			}
		}
		for(int j=0;j<V3.size();j++) T.set(V3[j].z0,0);
	}
	printf("%lld",ans);
}