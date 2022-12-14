#include <stdio.h>
#include <vector>

std::vector<int> save,V;
int x[2010],y[2010],next[2010],count[2010];
 
int find(int k)
{
	if(next[k]==k) return k;
	else return next[k] = find(next[k]);
}

int getSize(int a)
{
	int S = 0;
	for(int i=1;i<=a;i++) if(next[i]==i) S++;
	return S;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		
		int ans = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = 0;
		for(int i=1;i<=a;i++) next[i] = i;
		for(int i=1;i<=a;i++) if(x[i]==0) ans++, x[i]++;
		
		for(int i=1;i<=a;i++) for(int j=i+1;j<=a;j++) if((x[i]&x[j])>0) next[find(i)] = find(j);
		int C = 0,max = 0;
		for(int i=1;i<=a;i++) if(next[i]==i) C++;
		if(C==1)
		{
			printf("%d\n",ans);
			for(int i=1;i<=a;i++) printf("%d ",x[i]);
			printf("\n");
			continue;
		}
		
		for(int k=1;k<=a;k++)
		{
			x[k]--;
			for(int j=1;j<=a;j++) next[j] = j;
			for(int j=0;j<=30;j++)
			{
				save.clear();
				for(int i=1;i<=a;i++) if(((x[i]>>j)&1)==1) save.push_back(i);
				if(save.size()>1)
				{
					for(int i=1;i<save.size();i++)
					{
						int s = save[0], t = save[i];
						next[find(s)] = find(t);
					}
				}
			}
			
			if(getSize(a)==1)
			{
				printf("%d\n",ans+1);
				for(int i=1;i<=a;i++) printf("%d ",x[i]);
				printf("\n");
				goto u;
			}
			x[k]++;
		}
		for(int k=1;k<=a;k++)
		{
			x[k]++;
			for(int j=1;j<=a;j++) next[j] = j;
			for(int j=0;j<=30;j++)
			{
				save.clear();
				for(int i=1;i<=a;i++) if(((x[i]>>j)&1)==1) save.push_back(i);
				if(save.size()>1)
				{
					for(int i=1;i<save.size();i++)
					{
						int s = save[0], t = save[i];
						next[find(s)] = find(t);
					}
				}
			}
			
			if(getSize(a)==1)
			{
				printf("%d\n",ans+1);
				for(int i=1;i<=a;i++) printf("%d ",x[i]);
				printf("\n");
				goto u;
			}
			x[k]--;
		}
		
		for(int i=1;i<=a;i++)
		{
			int c = x[i];
			while(c%2==0) y[i]++, c/=2;
			max = max>y[i]?max:y[i];
		}
		if(max>0)
		{
			for(int i=1;i<=a;i++) if(y[i]==max) V.push_back(i);
			
			ans++;
			x[V[0]]--;
			if(V.size()>1)
			{
				ans++;
				x[V[1]]++;
			}
		}
		
		printf("%d\n",ans);
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("\n");
		u:;
	}
}