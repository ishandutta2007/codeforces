#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

char x[10],temp[10];
std::vector<int> save;
int y[100010];
int value[1000010];
std::map< std::pair<int,int> , int> M;

int number[1000010];
std::vector<int> V[1000010];
int check[1000010];
int control2 = 0;
void func(int k, int& C)
{
	if(control2) return;
	if(check[k]==1)
	{
		control2 = 1;
		return;
	}
	if(check[k]==2) return;
	
	check[k] = 1;
	for(int i=0;i<V[k].size();i++) func(V[k][i],C);
	check[k] = 2;
	number[k] = C--;
}

bool cmp(int a, int b)
{
	//printf("%d %d %d %d %d %d!!\n",a,b,y[a],y[b],number[y[a]],number[y[b]]);
	if(y[a]==y[b])
	{
		if(a==value[y[a]]) return true;
		else if(b==value[y[b]]) return true;
		return a<b;
	}
	else return number[y[a]]<number[y[b]];
}

int ans[100010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		for(int j=c+1;j<=4;j++) x[j] = '_';
		
		int S = 0;
		for(int j=1;j<=4;j++)
		{
			S*=27;
			if('a'<=x[j]&&x[j]<='z') S += (x[j]-'a'+1);
		}
		y[i] = S;
	}
	
	for(int i=1;i<=b;i++)
	{
		save.clear();
		int d;
		scanf("%s",x+1);
		for(int j=c+1;j<=4;j++) x[j] = '_';
		scanf("%d",&d);
		
		for(int k1=0;k1<=1;k1++)
		{
			if(c<1 && k1==1) continue;
			if(k1==0) temp[1] = '_';
			else temp[1] = x[1];
			for(int k2=0;k2<=1;k2++)
			{
				if(c<2 && k2==1) continue;
				if(k2==0) temp[2] = '_';
				else temp[2] = x[2];
				for(int k3=0;k3<=1;k3++)
				{
					if(c<3 && k3==1) continue;
					if(k3==0) temp[3] = '_';
					else temp[3] = x[3];
					for(int k4=0;k4<=1;k4++)
					{
						if(c<4 && k4==1) continue;
						if(k4==0) temp[4] = '_';
						else temp[4] = x[4];
						int S = 0;
						for(int j=1;j<=4;j++)
						{
							S*=27;
							if('a'<=temp[j]&&temp[j]<='z') S += (temp[j]-'a'+1);
						}
						save.push_back(S);
					}
				}
			}
		}
		
		int control = 0;
		for(int j=0;j<save.size();j++) if(save[j]==y[d]) control = 1;
		if(control==0)
		{
			printf("NO");
			return 0;
		}
		if(value[y[d]]!=0 && value[y[d]]!=d)
		{
			printf("NO");
			return 0;
		}
		value[y[d]] = d;
		
		for(int j=0;j<save.size();j++)
		{
			if(y[d]==save[j]) continue;
			V[y[d]].push_back(save[j]);
		}
	}
	
	int C = 1000000;
	for(int i=0;i<=1000000;i++) func(i,C);
	if(control2==1)
	{
		printf("NO");
		return 0;
	}
	
	for(int i=1;i<=a;i++) ans[i] = i;
	std::sort(ans+1,ans+a+1,cmp);
	
	printf("YES\n");
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}