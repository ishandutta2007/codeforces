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

const int N=105;

char a[N][N];
vector<pair<int,int> > ans;


int main()
{
	#ifdef LOCAL_TEST
		freopen("a.in","r",stdin);
//		freopen("e.out","w",stdout);
	#endif
	int n;
	cin>>n;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			cin>>a[i][j];
	bool flag=true;
	for (int i=1;i<=n;++i)
	{
		bool ok=true;
		for (int j=1;j<=n;++j)
			if (a[i][j]=='.')
			{
				ans.pb(mp(i,j));
				ok=false;
				break;
			}
		if (ok) flag=false;
	}
	if (flag)
	{
		for (int i=0;i<n;++i)
			cout<<ans[i].first<<' '<<ans[i].second<<endl;
		return 0;
	}
	flag=true;
	ans.clear();
	for (int j=1;j<=n;++j)
	{
		bool ok=true;
		for (int i=1;i<=n;++i)
			if (a[i][j]=='.')
			{
				ans.pb(mp(i,j));
				ok=false;
				break;
			}
		if (ok) flag=false;
	}
	if (flag)
	{
		for (int i=0;i<n;++i)
			cout<<ans[i].first<<' '<<ans[i].second<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}