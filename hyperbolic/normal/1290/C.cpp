#include <stdio.h>
#include <vector>
int size[600010],check[600010],next[600010];
int a,b;

int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}
int inverse(int k)
{
	if(k<=b) return find(k+b);
	else return find(k-b);
}

char x[600010];
std::vector<int> V[600010];
int main()
{
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
		{
			int d;
			scanf("%d",&d);
			V[d].push_back(i);
		}
	}
	for(int i=1;i<=2*b;i++) next[i] = i;
	for(int i=1;i<=b;i++) check[i] = 1;
	for(int i=b+1;i<=2*b;i++) size[i] = 1;
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='0')
		{
			if(V[i].size()==1)
			{
				int k = inverse(V[i][0]);
				k = find(k);
				if(check[k]==0)
				{
					ans -= size[inverse(k)];
					check[inverse(k)] = 0;
					check[k] = 2;
					ans += size[k];
				}
				else if(check[k]==1) check[k] = 2;
			}
			else if(V[i].size()==2)
			{
				int s1 = V[i][0], t1 = inverse(V[i][1]);
				s1 = find(s1);
				t1 = find(t1);
				if(s1!=t1)
				{
					if(check[s1]>=1) ans -= size[s1];
					if(check[t1]>=1) ans -= size[t1];
					next[t1] = s1;
					size[s1] += size[t1];
				}
				else if(check[s1]>=1) ans -= size[s1];
				
				int s2 = inverse(V[i][0]), t2 = V[i][1];
				s2 = find(s2);
				t2 = find(t2);
				if(s2!=t2)
				{
					if(check[s2]>=1) ans -= size[s2];
					if(check[t2]>=1) ans -= size[t2];
					next[t2] = s2;
					size[s2] += size[t2];
				}
				else if(check[s2]>=1) ans -= size[s2];
				
				if(check[s1]==2||check[t1]==2)
				{
					check[s1] = 2;
					check[s2] = 0;
					ans += size[s1];
				}
				else if(check[s2]==2||check[t2]==2)
				{
					check[s1] = 0;
					check[s2] = 2;
					ans += size[s2];
				}
				else
				{
					if(size[s1]>size[s2])
					{
						check[s1] = 0;
						check[s2] = 1;
						ans += size[s2];
					}
					else
					{
						check[s1] = 1;
						check[s2] = 0;
						ans += size[s1];
					}
				}
			}
		}
		
		if(x[i]=='1')
		{
			if(V[i].size()==1)
			{
				int k = V[i][0];
				k = find(k);
				if(check[k]==0)
				{
					ans -= size[inverse(k)];
					check[inverse(k)] = 0;
					check[k] = 2;
					ans += size[k];
				}
				else if(check[k]==1) check[k] = 2;
			}
			else if(V[i].size()==2)
			{
				int s1 = V[i][0], t1 = V[i][1];
				s1 = find(s1);
				t1 = find(t1);
				if(s1!=t1)
				{
					if(check[s1]>=1) ans -= size[s1];
					if(check[t1]>=1) ans -= size[t1];
					next[t1] = s1;
					size[s1] += size[t1];
				}
				else if(check[s1]>=1) ans -= size[s1];
				
				int s2 = inverse(V[i][0]), t2 = inverse(V[i][1]);
				s2 = find(s2);
				t2 = find(t2);
				if(s2!=t2)
				{
					if(check[s2]>=1) ans -= size[s2];
					if(check[t2]>=1) ans -= size[t2];
					next[t2] = s2;
					size[s2] += size[t2];
				}
				else if(check[s2]>=1) ans -= size[s2];
				
				if(check[s1]==2||check[t1]==2)
				{
					check[s1] = 2;
					check[s2] = 0;
					ans += size[s1];
				}
				else if(check[s2]==2||check[t2]==2)
				{
					check[s1] = 0;
					check[s2] = 2;
					ans += size[s2];
				}
				else
				{
					if(size[s1]>size[s2])
					{
						check[s1] = 0;
						check[s2] = 1;
						ans += size[s2];
					}
					else
					{
						check[s1] = 1;
						check[s2] = 0;
						ans += size[s1];
					}
				}
			}
		}
		
		printf("%d\n",ans);
	}
}