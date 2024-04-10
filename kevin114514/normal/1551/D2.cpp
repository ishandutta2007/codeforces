#include<bits/stdc++.h>
//AtCoder Library
//#define ATCODER
#ifdef ATCODER
#include<atcoder/convolution.hpp>
#include<atcoder/dsu.hpp>
#include<atcoder/fenwicktree.hpp>
#include<atcoder/internal_bit.hpp>
#include<atcoder/internal_math.hpp>
#include<atcoder/internal_queue.hpp>
#include<atcoder/internal_scc.hpp>
#include<atcoder/internal_type_traits.hpp>
#include<atcoder/lazysegtree.hpp>
#include<atcoder/math.hpp>
#include<atcoder/maxflow.hpp>
#include<atcoder/mincostflow.hpp>
#include<atcoder/modint.hpp>
#include<atcoder/scc.hpp>
#include<atcoder/segtree.hpp>
#include<atcoder/string.hpp>
#include<atcoder/twosat.hpp>
using namespace atcoder;
#endif
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
void die(string S){puts(S.c_str());exit(0);}
char grid[110][110];
bool check(int x,int y,char data)
{
	if(x<0||y<0)
		return false;
	return grid[x][y]==data;
}
void construct(int a,int b,int c)
{
//	cout<<a<<" "<<b<<" "<<c<<endl;
	memset(grid,0,sizeof(grid));
	char data='a';
	c-=(b%2)*(a/2);
	for(int i=0;i<a-1;i+=2)
	{
		int mx=min(b,c);
		if(mx%2)
			mx--;
		c-=mx;
		mx+=b%2;
		for(int j=0;j<mx;j++)
		{
			if(data=='z')
				data='a';
			else	data++;
			while(check(i-1,j,data)||check(i,j+1,data)||check(i,j-1,data)||check(i+1,j+1,data)||check(i+1,j-1,data)||check(i+2,j,data))
			{	
				if(data=='z')
					data='a';
				else	data++;
			}
			grid[i][j]=grid[i+1][j]=data;
		}
	}
//	if(c)
//	{
//		puts("NO");
//		return ;
//	}
	puts("YES");
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			if(!grid[i][j])
			{
				if(data=='z')
					data='a';
				else	data++;
				while(check(i-1,j,data)||check(i-1,j+1,data)||check(i,j-1,data)||check(i,j+2,data)||check(i+1,j,data)||check(i+1,j+1,data))
				{	
					if(data=='z')
						data='a';
					else	data++;
				}
				grid[i][j]=grid[i][j+1]=data;
			}
	for(int i=0;i<a;i++)
	{
//		cout<<i+1<<" ";
		for(int j=0;j<b;j++)
			cout<<grid[i][j];
		puts("");
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(c<0)
		{
			puts("NO");
			continue;
		}
		c=a*b/2-c;
		if(c<0)
		{
			puts("NO");
			continue;
		}
		if(b==1)
		{
			if(c*2==a*b)
			{
				construct(a,b,c);
			}
			else	puts("NO");
			continue;
		}
		if(a==1)
		{
			if(!c)
			{
				construct(a,b,c);
			}
			else	puts("NO");
			continue;
		}
		int black=(a+1)/2*b;
		int white=a*b-black;
		if((black-c)%2||(white-c)%2||(black<c)||(white<c))
		{
			puts("NO");
			continue;
		}
		swap(a,b);
		c=a*b/2-c;
		black=(a+1)/2*b;
		white=a*b-black;
		if((black-c)%2||(white-c)%2||(black<c)||(white<c))
			puts("NO");
		else
		{
			construct(b,a,a*b/2-c);
		}
	}
	return 0;
}