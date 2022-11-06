#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int g[500005];
int ro[500005];
int find_set(int v) {
    if (v == g[v])
        return v;
    return g[v]=find_set(g[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        g[b] = a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		FOR(i,0,n+1)
		g[i]=i;
		int k,o,p;
		FOR(i,0,m)
		{
			cin>>k;
			if(k>0)
			cin>>o;
			FOR(i,1,k)
			{
				cin>>p;
				union_sets(o,p);
//				cout<<o<<' '<<p<<'\n';
			}
		}
		FOR(i,1,n+1)
		{
			ro[find_set(i)]++;
		}
		FOR(i,1,n+1)
		{
			cout<<ro[g[i]]<<' ';
		}
	}
	return 0;
}