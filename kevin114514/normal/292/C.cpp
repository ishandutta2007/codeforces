#include<bits/stdc++.h>
#include<map>
int IP[100100][4];
int sz;
int N;
int can[10];
int Div[15][1000][4];
int DDiv[15];
int Num[15];
int maskn;
using namespace std;
inline bool need(int x)
{
	int mask=0;
	for(int i=0;i<x;i++)
		mask|=(1<<Num[i]);
	return mask==maskn;
}
void Cons1(int x)
{
	if(!need(x))
		return ;
	for(int i=x;i<x+x-1;i++)
		Num[i]=Num[x+x-i-2];
	for(int i=0;i<DDiv[x+x-1];i++)
	{
		int aa=0,bb=0,cc=0,dd=0;
		int Tmp=0;
		if(!Num[Tmp]&&Div[x+x-1][i][0]>1)
			continue;
		for(int j=0;j<Div[x+x-1][i][0];j++)
		{
			aa*=10;
			aa+=Num[Tmp++];
		}
		if(!Num[Tmp]&&Div[x+x-1][i][1]>1)
			continue;
		for(int j=0;j<Div[x+x-1][i][1];j++)
		{
			bb*=10;
			bb+=Num[Tmp++];
		}
		if(!Num[Tmp]&&Div[x+x-1][i][2]>1)
			continue;
		for(int j=0;j<Div[x+x-1][i][2];j++)
		{
			cc*=10;
			cc+=Num[Tmp++];
		}
		if(!Num[Tmp]&&Div[x+x-1][i][3]>1)
			continue;
		for(int j=0;j<Div[x+x-1][i][3];j++)
		{
			dd*=10;
			dd+=Num[Tmp++];
		}
		if(aa<256&&bb<256&&cc<256&&dd<256)
			IP[sz][0]=aa,
			IP[sz][1]=bb,
			IP[sz][2]=cc,
			IP[sz++][3]=dd;
	} 
}
void Cons2(int x)
{
	if(!need(x))
		return ;
	for(int i=x;i<x+x;i++)
		Num[i]=Num[x+x-i-1];
	for(int i=0;i<DDiv[x+x];i++)
	{
		int aa=0,bb=0,cc=0,dd=0;
		int Tmp=0;
		if(!Num[Tmp]&&Div[x+x][i][0]>1)
			continue;
		for(int j=0;j<Div[x+x][i][0];j++)
		{
			aa*=10;
			aa+=Num[Tmp++];
		}
		if(!Num[Tmp]&&Div[x+x][i][1]>1)
			continue;
		for(int j=0;j<Div[x+x][i][1];j++)
		{
			bb*=10;
			bb+=Num[Tmp++];
		}
		if(!Num[Tmp]&&Div[x+x][i][2]>1)
			continue;
		for(int j=0;j<Div[x+x][i][2];j++)
		{
			cc*=10;
			cc+=Num[Tmp++];
		}
		if(!Num[Tmp]&&Div[x+x][i][3]>1)
			continue;
		for(int j=0;j<Div[x+x][i][3];j++)
		{
			dd*=10;
			dd+=Num[Tmp++];
		}
		if(aa<256&&bb<256&&cc<256&&dd<256)
			IP[sz][0]=aa,
			IP[sz][1]=bb,
			IP[sz][2]=cc,
			IP[sz++][3]=dd;
	} 
}
void dfs(int x)
{
	if(x>6)
		return ;
	if(x>=2&&x<=6)
	{
		Cons1(x);
		Cons2(x);
	}
	for(int i=0;i<N;i++)
	{
		Num[x]=can[i];
		dfs(x+1);
	}
}
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>can[i];
		maskn|=(1<<can[i]);
	}
		for(int _1=1;_1<=3;_1++)
			for(int _2=1;_2<=3;_2++)
				for(int _3=1;_3<=3;_3++)
					for(int _4=1;_4<=3;_4++)
						{
						    int i=_1+_2+_3+_4;
							Div[i][DDiv[i]][0]=_1,
							Div[i][DDiv[i]][1]=_2,
							Div[i][DDiv[i]][2]=_3,
							Div[i][DDiv[i]][3]=_4;
							DDiv[i]++;
						}
	dfs(0);
	printf("%d\n",sz);
	for(int i=0;i<sz;i++)
	{
		printf("%d.%d.%d.%d\n",IP[i][0],IP[i][1],IP[i][2],IP[i][3]);
	}
	return 0;
}