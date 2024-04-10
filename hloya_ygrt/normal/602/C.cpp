#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;
const int INF=2e9;
int main()
{
    int n;
    scanf("%d",&n);
    vector <vector <pair< int,int > > > g(n),a(n);

    int k;
    scanf("%d",&k);
    for (int i=0;i<k;i++)
    {
        int f,t;
        scanf("%d %d",&f,&t);
        f--; t--;
        g[f].push_back(make_pair(t,1));
         g[t].push_back(make_pair(f,1));
    }

    for (int i=0;i<n;i++)
    {
        int was[400]={0};

        for (int j=0;j<g[i].size();j++)
            was[g[i][j].first]=1;
        for (int j=0;j<n;j++)
            if (was[j]==0)
        {
           a[i].push_back(make_pair(j,1));
        }
    }
    int s=0;

	vector<int> d (n, INF);  //p (n);
	d[s] = 0;
	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = true;

		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				//p[to] = v;
			}
		}
	}

	  s=0;
    vector<int> d1 (n, INF);
	d1[s] = 0;
	vector<char> u1 (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u1[j] && (v == -1 || d1[j] < d1[v]))
				v = j;
		if (d1[v] == INF)
			break;
		u1[v] = true;

		for (size_t j=0; j<a[v].size(); ++j) {
			int to = a[v][j].first,
				len = a[v][j].second;
			if (d1[v] + len < d1[to]) {
				d1[to] = d1[v] + len;
				//p[to] = v;
			}
		}
	}
	if (d1[n-1]==INF||d[n-1]==INF)
        printf("-1");
    else
        printf("%d",max(d1[n-1],d[n-1]));
    return 0;
}