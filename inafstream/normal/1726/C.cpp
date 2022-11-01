#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n;
char a[200005];
int s[200005];

vector<int> v[400005];
int fa[200005];
int fnd(int x){if(fa[x]==x)return x;return fa[x]=fnd(fa[x]);}

void solve()
{
	scanf("%d",&n);n*=2;
	s[0]=n+1;
	rep(i,n+n+1) v[i].clear();
	rep(i,n)
	{
		while((a[i]=getchar())!='('&&a[i]!=')');
		s[i]=s[i-1]+(a[i]=='('?1:-1);
	}
	rep(i,n) fa[i]=i;
	rep(i,n)
	{
		if(a[i]=='(') v[s[i]-1].push_back(i);
		else
		{
			if(!v[s[i]].empty())
			{
				while(!v[s[i]].empty())
				{
				fa[fnd(v[s[i]].back())]=fnd(i);
					v[s[i]].pop_back();
				}
				v[s[i]].push_back(i);
			}
			v[s[i-1]].clear();
		}
	}
	set<int> st;
	rep(i,n) st.insert(fnd(i));
	printf("%d\n",(int)st.size());
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}