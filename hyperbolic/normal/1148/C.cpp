#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int x0;
	int y0;
}y[300010];

bool cmp(str a, str b)
{
	return a.y0<b.y0;
}

int abs(int k)
{
	return k>0?k:-k;
}

int x[300010],next[300010];
void swap(int s, int t)
{
	next[x[s]] = t;
	next[x[t]] = s;
	
	int k = x[s];
	x[s] = x[t];
	x[t] = k;
}
std::vector< std::pair<int,int> > V;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = {x[i],i};
	std::sort(y+1,y+a+1,cmp);
	for(int i=1;i<=a;i++) next[y[i].x0] = i;
	
	for(int i=2;i<=a-1;i++)
	{
		if(i==next[i]) continue;
		
		if(i<=a/2&&next[i]<=a/2)
		{
			V.push_back(std::make_pair(i,a));
			V.push_back(std::make_pair(next[i],a));
			V.push_back(std::make_pair(i,a));
			swap(i,next[i]);
		}
		else if(i<=a/2&&next[i]>a/2)
		{
			if(next[i]==a)
			{
				V.push_back(std::make_pair(i,next[i]));
				swap(i,next[i]);
			}
			else
			{
				V.push_back(std::make_pair(i,a));
				V.push_back(std::make_pair(next[i],1));
				V.push_back(std::make_pair(1,a));
				V.push_back(std::make_pair(i,a));
				V.push_back(std::make_pair(next[i],1));
				swap(i,next[i]);
			}
		}
		else if(i>a/2&&next[i]<=a/2)
		{
			if(next[i]==1)
			{
				V.push_back(std::make_pair(i,next[i]));
				swap(i,next[i]);
			}
			else
			{
				V.push_back(std::make_pair(i,1));
				V.push_back(std::make_pair(next[i],a));
				V.push_back(std::make_pair(1,a));
				V.push_back(std::make_pair(i,1));
				V.push_back(std::make_pair(next[i],a));
				swap(i,next[i]);
			}
		}
		else
		{
			V.push_back(std::make_pair(i,1));
			V.push_back(std::make_pair(next[i],1));
			V.push_back(std::make_pair(i,1));
			swap(i,next[i]);
		}
	}
	
	if(next[1]==1&&next[a]==a);
	else if(next[1]==a&&next[a]==1)
	{
		V.push_back(std::make_pair(1,a));
	}
	else while(1);
	printf("%d\n",V.size());
	for(int i=0;i<V.size();i++) printf("%d %d\n",V[i].first,V[i].second);
}