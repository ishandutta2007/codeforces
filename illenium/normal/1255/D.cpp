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
#define maxn 10000005
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

string s="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789*";
vector < vector <int> > mp,ans;
char s1[maxn];
int tx,ty,m,n,k;

inline void nxt()
{
	if(tx%2==0)
	{
		if(ty==m-1) tx++;
		else ty++;
	}
	else
	{
		if(ty==0) tx++;
		else ty--;
	}
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(),m=read(),k=read(); int cnt=0;
		mp.clear(); ans.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s1+1);
			vector <int> vec; vec.clear();
			for(int j=1;j<=m;j++)
			{
				if(s1[j]=='.') vec.push_back(0);
				else vec.push_back(1),cnt++;
			}
			mp.push_back(vec);
			ans.push_back(vec);
		}
		int tmp=cnt/k,tmp2=cnt%k;
		tx=0,ty=0;
		int nw=0,tmp3=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				//cout<<tx<<" "<<ty<<" "<<nw<<endl;
				if(mp[tx][ty]==0) ans[tx][ty]=nw;
				else
				{
					tmp3++; ans[tx][ty]=nw;
					if(tmp2)
					{
						if(tmp3==tmp+2) {tmp3=1; nw++; tmp2--; ans[tx][ty]=nw;}
					}
					else
					{
						if(tmp3==tmp+1) {tmp3=1; nw++; ans[tx][ty]=nw;}
					}
				}
				//cout<<"Askljd"<<endl;
				nxt();
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				printf("%c",s[ans[i][j]]);
			}
			puts("");
		}
	}
	return 0;
}