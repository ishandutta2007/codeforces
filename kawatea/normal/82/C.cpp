#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector < pair<int, int> > g[5001];
int parent[5000][2];

void set_parent(int x)
{
     int i;

     for (i = 0; i < g[x].size(); i++) {
          if (parent[g[x][i].first][0] == -1) {
               parent[g[x][i].first][0] = x;
               parent[g[x][i].first][1] = g[x][i].second;

               set_parent(g[x][i].first);
          }
     }
}

int main()
{
     int n, a, b, c, i, j;
     vector < pair<int, int> > v;
     int p[5001], q[5001], f[5001];

     scanf("%d", &n);

     for (i = 1; i <= n; i++) {
	  parent[i][0] = -1;
	  q[i] = i;
	  f[i] = 0;
     }
     parent[1][0] = 1;

     for (i = 0; i < n; i++) {
          scanf("%d", &a);

          v.push_back(make_pair(a, i + 1));
     }

     for (i = 0; i < n - 1; i++) {
          scanf("%d %d %d", &a, &b, &c);
          
          g[a].push_back(make_pair(b, c));
          g[b].push_back(make_pair(a, c));
     }

     sort(v.begin(), v.end());

     set_parent(1);

     for (i = 0; i <= n; i++) {
	  int t[5001] = {0};

	  for (j = 0; j < n; j++) {
	       int x = v[j].second;

	       if (f[x] == 0) {
		    if (q[x] == 1) {
			 p[x] = i;
			 f[x] = 1;
		    } else {
			 if (t[q[x]] < parent[q[x]][1]) {
			      t[q[x]]++;
			      q[x] = parent[q[x]][0];
			 }
		    }
	       }
	  }
     }

     for (i = 1; i <= n; i++) {
          if (i > 1) putchar(' ');

          printf("%d", p[i]);
     }

     puts("");

     return 0;
}