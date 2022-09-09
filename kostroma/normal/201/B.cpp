#pragma comment(linker, "/STACK:106777216")

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;
#define NAME "circles"
int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#else
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);
	int t = 1;
	//cin>>t;
	while (t--)
	{
		solve();
	}
	return 0;
}

#define int li

int n, m;
int c[1010][1010];
int sumkv=0, sum=0, sumstr=0, sumstolb=0;

void solve(){
	cin>>n>>m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin>>c[i][j], sum+=c[i][j], sumstr+=c[i][j]*(4*i+2), sumstolb+=c[i][j]*(4*j+2), sumkv+=c[i][j]*((4*i+2)*(4*i+2)+(4*j+2)*(4*j+2));

	int ans=1LL<<60;
	int x=-1, y=-1;

	for (int l1=0; l1<=n; l1++)
		for (int l2=0; l2<=m; l2++)
		{
			int xx=4*l1, yy=4*l2;
			int cur=sumkv+sum*( xx*xx+yy*yy )-2*sumstr*xx-2*sumstolb*yy;
			if (cur<ans)
			{
				ans=cur;
				x=l1;
				y=l2;
			}
		}
	cout<<ans<<endl;
	cout<<x<<' '<<y<<endl;
	
}