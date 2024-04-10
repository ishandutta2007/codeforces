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
#include <bitset>

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

int a[N][N],n,m,size[N];
long long b[N][N];
bitset<N> c[N],d;
vector<int> s,t;

bool check(int mid)
{
	for (int i=0;i<n;++i)
		for (int k=0;k<=(m-1)/60;++k)
			b[i][k]=0;
	for (int i=0;i<n;++i)
	{
		size[i]=0;
		for (int j=0;j<m;++j)
			if (a[i][j]>=mid)
			{
				b[i][j/60]+=(1LL<<(j%60));
				++size[i];
			}
	}
	for (int i=0;i<n;++i) if (size[i]>=2)
		for (int j=i+1;j<n;++j) if (size[j]>=2)
		{
			int c=0;
			for (int k=0;k<=(m-1)/60;++k)
			{
				long long t=b[i][k]&b[j][k];
				while (t)
				{
					t-=(t&(t^(t-1)));
					++c;
					if (c>=2) return true;
				}
			}
		}
/*	for (int i=0;i<n;++i)
		for (int j=0;j<m;++j)
			c[i][j]=(a[i][j]>=mid);
	for (int i=0;i<n;++i)
		for (int j=i+1;j<n;++j)
			{
				d=c[i]&c[j];
				if (d.count()>=2) return true;
			}*/
	return false;
}

int main()
{
	#ifdef LOCAL_TEST
	//	freopen("a.in","r",stdin);
	//	freopen("a.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i)
		for (int j=0;j<m;++j)
		{
			scanf("%d",&a[i][j]);
			t.pb(a[i][j]);
		}
	sort(t.begin(),t.end());
	s.pb(t[0]);
	for (int i=1;i<sz(t);++i)
		if (t[i]!=t[i-1])
			s.pb(t[i]);
	int L=0,R=1000000000;
	while (L<R)
	{
		int mid=(L+R+1)/2;
		if (check(mid)) L=mid;
		else R=mid-1;
	}
	cout<<L<<endl;
	return 0;
}