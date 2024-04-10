#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
const int B=450;
const int N=200200;
int cnt[B+5][B+5];
int delta[N];
int x[N],y[N];
int add[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	int Delta=0;
	for(register int i=1;i<=m;i++)
	{
		int op,ind;
		scanf("%d%d",&op,&ind);
		if(op==1)
		{
			add[ind]=i;
			if(x[ind]+y[ind]<=B)
			{
				for(int j=x[ind]+1;j<=x[ind]+y[ind];j++)
					cnt[(i+j-1)%(x[ind]+y[ind])][x[ind]+y[ind]]+=1;
			}
			else
			{
				for(register int j=i+x[ind];j<=m;j+=x[ind]+y[ind])
				{
					delta[j]++;
					if(j+y[ind]<=m)
						delta[j+y[ind]]--;
				}
			}
		}
		else
		{
			if(x[ind]+y[ind]<=B)
			{
				for(register int j=x[ind]+1;j<=x[ind]+y[ind];j++)
					cnt[(add[ind]+j-1)%(x[ind]+y[ind])][x[ind]+y[ind]]-=1;
			}
			else
			{
				for(register int j=add[ind]+x[ind];j<=m;j+=x[ind]+y[ind])
				{
					delta[j]--;
					if(j<i&&i<=j+y[ind])
						delta[i]--;
					if(j+y[ind]<=m)
						delta[j+y[ind]]++;
				}
			}
		}
		Delta+=delta[i];
		int ans=Delta;
		for(int j=2;j<=B;j++)
			ans+=cnt[i%j][j];
		printf("%d\n",ans);
	}
	return 0;
}