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
	while(c<'0'||c>'9'){if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll m;
int n,ans,t,s[105];

int main()
{
	cin>>m;
	ans = 1000;
	while (m > 0)
	{
		s[n]= m % 10;
		m /= 10;
		++n;
	}
	int f = 0;
	for (int i=0;i<n;++i)
	{
		for (int j=0; j<n;++j)
		{
			if (i == j)
			continue;
			if (s[i]==0&&s[j]==0||s[i]==5&&s[j]==0||s[i]==7&&s[j]==5||s[i]==2&&s[j]==5)
			{
				t = i + j;
				if (i > j)
				t -= 1;
				f= 2;
				for (int k = n - 1; k >=-1;--k)
				{
					if (k ==i||k==j)
					continue;
					if (k==-1)
					{
						if(f==1) f = 0;
						break;
					}
					if (s[k]== 0)++t,f=1;
					else break;
				}
				if (f&& t< ans)
				ans = t;
			}
		}
	}
	if (ans>100)
	ans=-1;
	cout<<ans;
}