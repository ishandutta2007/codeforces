#include <stdio.h>
#include <algorithm>
#include <vector>

int getQuery(int s, int t)
{
	printf("? %d %d\n",s,t);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

std::vector<int> V,W;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		int b = (1<<a);
		for(int i=1;i<=b;i++) V.push_back(i);
		
		while(V.size()>=4)
		{
			W.clear();
			for(int j=0;j<V.size();j+=4)
			{
				int val = getQuery(V[j],V[j+2]);
				if(val==1)
				{
					int val2 = getQuery(V[j],V[j+3]);
					if(val2==1) W.push_back(V[j]);
					else W.push_back(V[j+3]);
				}
				else if(val==2)
				{
					int val2 = getQuery(V[j+1],V[j+2]);
					if(val2==2) W.push_back(V[j+2]);
					else W.push_back(V[j+1]);
				}
				else
				{
					int val2 = getQuery(V[j+1],V[j+3]);
					if(val2==1) W.push_back(V[j+1]);
					else W.push_back(V[j+3]);
				}
			}
			V.clear();
			for(int i=0;i<W.size();i++) V.push_back(W[i]);
		}
		
		int ans;
		if(V.size()==1) ans = V[0];
		else
		{
			int val = getQuery(V[0],V[1]);
			if(val==1) ans = V[0];
			else ans = V[1];
		}
		
		printf("! %d\n",ans);
		fflush(stdout);
	}
}