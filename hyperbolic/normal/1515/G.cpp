#include <stdio.h>
#include <vector>

int check[200010];
std::vector<int> St;
std::vector< std::pair<int,int> > V[200010];
std::vector<int> V2[200010];

void func(int k)
{
	if(check[k]) return;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++) func(V[k][i].first);
	St.push_back(k);
}

int color[200010];
void func2(int k, int &C)
{
	if(color[k]) return;
	color[k] = C;
	for(int i=0;i<V2[k].size();i++)
	{
		func2(V2[k][i],C);
	}
}

long long int D[200010];
long long int value[200010];

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int abs(long long int k)
{
	return k>0?k:-k;
}

void func3(int k, long long int dist, int C)
{
	D[k] = dist;
	for(int i=0;i<V[k].size();i++)
	{
		if(color[V[k][i].first]!=C) continue;
		
		if(D[V[k][i].first]!=-1) value[color[k]] = gcd(value[color[k]],abs(D[V[k][i].first]-(dist+V[k][i].second)));
		else func3(V[k][i].first,dist+V[k][i].second,C);
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back({d,e});
		V2[d].push_back(c);
	}
	
	for(int i=1;i<=a;i++) func(i);
	
	int C = 1;
	while(!St.empty())
	{
		int k = St.back();
		if(color[k]==0)
		{
			func2(k,C);
			C++;
		}
		St.pop_back();
	}
	
	for(int i=1;i<=a;i++) D[i] = -1;
	for(int i=1;i<=a;i++) if(D[i]==-1) func3(i,0,color[i]);
	
	/*
	for(int i=1;i<=a;i++) printf("%d ",color[i]);
	printf("\n");
	for(int i=1;i<=a;i++) printf("%lld ",value[i]);
	printf("\n");
	*/
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		if((f-e)%gcd(f,value[color[d]])==0) printf("YES\n");
		else printf("NO\n");
	}
}