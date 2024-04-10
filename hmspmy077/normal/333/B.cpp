#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

typedef long long int64;

#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define ms(a,x)

const int N=1005;

int f[N],g[N];

int main()
{
	#ifdef LOCAL_TEST
	//	freopen("a.in","r",stdin);
	//	freopen("a.out","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	while (m--)
	{
		int x,y;
		cin>>x>>y;
		f[x]=true;
		g[y]=true;
	}
	int ans=0;
	for (int i=2,j=n-1;i<=j;++i,--j)
	{
		int t=0;
		for (int a=-1;a<=1;++a)
			for (int b=-1;b<=1;++b)
				for (int c=-1;c<=1;++c)
					for (int d=-1;d<=1;++d)
					{
						if (f[i] && a!=0) continue;
						if (f[j] && b!=0) continue;
						if (g[i] && c!=0) continue;
						if (g[j] && d!=0) continue;
						if (i==j && a!=b) continue;
						if (i==j && c!=d) continue;
						if (a!=0 && c!=0 && a==c) continue;
						if (b!=0 && d!=0 && b==d) continue;
						if (a!=0 && d!=0 && a==-d) continue;
						if (b!=0 && c!=0 && b==-c) continue;
						int tmp=(a!=0)+(b!=0)+(c!=0)+(d!=0);
						if (i==j) tmp/=2;
						t=max(t,tmp);
					}
		ans+=t;
	}
	cout<<ans<<endl;
	return 0;
}