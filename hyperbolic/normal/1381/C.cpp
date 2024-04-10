#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

struct str{
	int x0;
	int y0;
};
bool operator<(str a, str b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0>b.x0;
}
std::set<str> S;

int a,b,c,d;
int check[100010];
int control = 0;
int x[100010],y[100010];
std::vector<int> T1,T2,T3;
std::vector<int> count[100010];

void func1()
{
	//for(int i=0;i<T1.size();i++) printf("%d??\n",T1[i]);
	for(int i=0;i<T1.size();i++) y[T1[i]] = x[T1[i]];
}

str z[100010];
int w[100010];
int func3()
{
	for(int i=1;i<=a+1;i++) check[i] = 0;
	for(int i=1;i<=a;i++) check[x[i]] = 1;
	for(int i=1;i<=a+1;i++) if(check[i]==0) return i;
}

void func2()
{
	for(int i=1;i<=a+1;i++) z[i] = {count[i].size(),i};
	std::sort(z+1,z+a+2);
	
	int p = 0;
	for(int i=1;i<=a+1;i++)
	{
		int y0 = z[i].y0;
		for(int j=0;j<count[y0].size();j++) w[p++] = count[y0][j];
	}
	
	int start = 0;
	for(int i=1;i<p;i++)
	{
		if(x[w[i]]!=x[w[0]])
		{
			start = i;
			break;
		}
	}
	
	for(int i=0;i<p;i++) y[w[(start+i)%p]] = x[w[i]];
	int e = a-c;
	int left = func3();
	int C = 0;
	
	for(int i=0;i<p;i++)
	{
		if(y[w[i]]==x[w[i]])
		{
			C++;
			y[w[i]] = left;
		}
	}
	if(C<=e)
	{
		for(int i=C;i<p;i++)
		{
			if(C==e) break;
			y[w[i]] = left;
			C++;
		}
	}
	else control = 1;
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		control = 0;
		T1.clear();
		T2.clear();
		T3.clear();
		S.clear();
		
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a+1;i++) count[i].clear();
		
		d = c-b;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) count[x[i]].push_back(i);
		for(int i=1;i<=a+1;i++) S.insert({count[i].size(),i});
		
		for(int i=1;i<=b;i++)
		{
			std::set<str> ::iterator it = S.begin();
			int value = (*it).x0;
			int index = (*it).y0;
			//printf("%d %d!!\n",value,index);
			T1.push_back(count[index][count[index].size()-1]);
			count[index].pop_back();
			S.erase(it);
			S.insert({count[index].size(),index});
		}
		
		func1();
		func2();
		if(control==1) printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=1;i<=a;i++) printf("%d ",y[i]);
			printf("\n");
		}
	}
}