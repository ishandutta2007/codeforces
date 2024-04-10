#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m;
vector <int> vec1,vec2;

int main()
{
	cin>>n>>m;
	if(n-1>m)
	{
		puts("Impossible");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int t=__gcd(i,j);
			if(t==1)
			{
				m--;
				vec1.push_back(i);
				vec2.push_back(j);
				if(m==0)
				{
					puts("Possible");
					for(int k=0;k<vec1.size();k++) printf("%d %d\n",vec1[k],vec2[k]);
					return 0;
				}
			}
		}
	}
	puts("Impossible");
	return 0;
}