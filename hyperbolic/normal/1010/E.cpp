#include <stdio.h>
#include <vector>
#include <algorithm>

int xLeft = 123456, xRight;
int yLeft = 123456, yRight;
int zLeft = 123456, zRight;
std::vector< std::pair<int,int> > value[500010];
std::vector<int> leftMin[500010], rightMin[500010];
std::vector<int> leftMax[500010], rightMax[500010];
	
struct SegTree{
	
	void insert(int index, std::pair<int,int> val, int l=1, int r=100000,int v=1)
	{
		if(l==r)
		{
			value[v].push_back(val);
			return;
		}
		int h = (l+r)/2;
		if(index<=h) insert(index,val,l,h,2*v);
		else insert(index,val,h+1,r,2*v+1);
	}
	void init(int l=1, int r=100000, int v=1)
	{
		if(l==r) std::sort(value[v].begin(),value[v].end());
		if(l<r)
		{
			int h = (l+r)/2;
			init(l,h,2*v);
			init(h+1,r,2*v+1);
			//merge
			int s=0, t=0;
			while(s<value[2*v].size()||t<value[2*v+1].size())
			{
				if(s==value[2*v].size()) value[v].push_back(value[2*v+1][t++]);
				else if(t==value[2*v+1].size()) value[v].push_back(value[2*v][s++]);
				else
				{
					if(value[2*v][s].first<value[2*v+1][t].first) value[v].push_back(value[2*v][s++]);
					else value[v].push_back(value[2*v+1][t++]);
				}
			}
		}
		
		
		// set Left, Right
		if(value[v].size()>=1)
		{
			for(int i=0;i<value[v].size();i++)
			{
				leftMin[v].push_back(123456);
				leftMax[v].push_back(0);
				rightMin[v].push_back(123456);
				rightMax[v].push_back(0);
			}
			
			int p = -1;
			for(int i=value[v].size()-1;i>=0;i--)
			{
				if(value[v][i].first<=yRight)
				{
					p = i;
					break;
				}
			}
			if(p>=0)
			{
				if(value[v][p].second>=zLeft) leftMin[v][p] = value[v][p].second;
				if(value[v][p].second<=zRight) leftMax[v][p] = value[v][p].second;
				for(int i=p-1;i>=0;i--)
				{
					leftMin[v][i] = leftMin[v][i+1];
					leftMax[v][i] = leftMax[v][i+1];
					if(value[v][i].second>=zLeft) leftMin[v][i] = leftMin[v][i]<value[v][i].second?leftMin[v][i]:value[v][i].second; 
					if(value[v][i].second<=zRight) leftMax[v][i] = leftMax[v][i]>value[v][i].second?leftMax[v][i]:value[v][i].second;
				}
			}
			
			p = value[v].size();
			for(int i=0;i<value[v].size();i++)
			{
				if(value[v][i].first>=yLeft)
				{
					p = i;
					break;
				}
			}
			if(p<value[v].size())
			{
				if(value[v][p].second>=zLeft) rightMin[v][p] = value[v][p].second;
				if(value[v][p].second<=zRight) rightMax[v][p] = value[v][p].second;
				for(int i=p+1;i<value[v].size();i++)
				{
					rightMin[v][i] = rightMin[v][i-1];
					rightMax[v][i] = rightMax[v][i-1];
					if(value[v][i].second>=zLeft) rightMin[v][i] = rightMin[v][i]<value[v][i].second?rightMin[v][i]:value[v][i].second; 
					if(value[v][i].second<=zRight) rightMax[v][i] = rightMax[v][i]>value[v][i].second?rightMax[v][i]:value[v][i].second;
				}
			}
		}
	}
	
	int getCount(int xL, int xR, int yL, int yR, int zL, int zR, int l=1, int r=100000, int v=1)
	{
		if(xL<=l&&r<=xR)
		{
			if(value[v].size()==0) return 0;
			if(yL==yLeft)
			{
				int limit = -1;
				int min = 0, max = value[v].size()-1;
				//printf("%d %d: %d!!\n",l,r,value[v].size());
				while(min<=max)
				{
					int h = (min+max)/2;
					if(value[v][h].first<=yR)
					{
						limit = h;
						min = h+1;
					}
					else max = h-1;
				}
				if(limit==-1) return 0;
				else
				{
					if(zL==zLeft)
					{
						if(rightMin[v][limit]<=zR) return 1;
						else return 0;
					}
					else
					{
						if(rightMax[v][limit]>=zL) return 1;
						else return 0;
					}
				}
			}
			else if(yR==yRight)
			{
				int limit = -1;
				int min = 0, max = value[v].size()-1;
				//printf("%d %d : %d\n",l,r,value[v].size());
				while(min<=max)
				{
					int h = (min+max)/2;
					if(value[v][h].first>=yL)
					{
						limit = h;
						max = h-1;
					}
					else min = h+1;
				}
				if(limit==-1) return 0;
				else
				{
					if(zL==zLeft)
					{
						if(leftMin[v][limit]<=zR) return 1;
						else return 0;
					}
					else
					{
						if(leftMax[v][limit]>=zL) return 1;
						else return 0;
					}
				}
			}
			else
			{
				printf("!!\n");
				return 1;
			}
		}
		else if(xR<l) return 0;
		else if(r<xL) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getCount(xL,xR,yL,yR,zL,zR,l,h,2*v);
			int s2 = getCount(xL,xR,yL,yR,zL,zR,h+1,r,2*v+1);
			return s1+s2;
		}
	}
	
}T;

int main()
{
	int xMax,yMax,zMax;
	scanf("%d%d%d",&xMax,&yMax,&zMax);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		xLeft = xLeft<d?xLeft:d;
		xRight = xRight>d?xRight:d;
		yLeft = yLeft<e?yLeft:e;
		yRight = yRight>e?yRight:e;
		zLeft = zLeft<f?zLeft:f;
		zRight = zRight>f?zRight:f;
	}
	for(int i=1;i<=b;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		if(xLeft<=d&&d<=xRight&&yLeft<=e&&e<=yRight&&zLeft<=f&&f<=zRight)
		{
			printf("INCORRECT");
			return 0;
		}
		T.insert(d,std::make_pair(e,f));
	}
	
	T.init();
	printf("CORRECT\n");
	for(int i=1;i<=c;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		if(xLeft<=d&&d<=xRight&&yLeft<=e&&e<=yRight&&zLeft<=f&&f<=zRight) printf("OPEN\n");
		else
		{
			int xL,xR,yL,yR,zL,zR;
			xL = xLeft<d?xLeft:d;
			xR = xRight>d?xRight:d;
			yL = yLeft<e?yLeft:e;
			yR = yRight>e?yRight:e;
			zL = zLeft<f?zLeft:f;
			zR = zRight>f?zRight:f;
			int s = T.getCount(xL,xR,yL,yR,zL,zR);
			if(s==0) printf("UNKNOWN\n");
			else printf("CLOSED\n");
		}
	}
}