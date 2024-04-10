#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int f[100000] = {0};
int p[100000];
long long d[100000];
vector <pair<int, int> > v[100000];
priority_queue <pair<long long, int> > q;

int main()
{
     int n, m, i, j;

     scanf("%d %d", &n, &m);

     for (i = 0; i < m; i++) {
	  int a, b, w;

	  scanf("%d %d %d", &a, &b, &w);

	  if (a == b) continue;

	  a--;
	  b--;

	  v[a].push_back(make_pair(b, w));
	  v[b].push_back(make_pair(a, w));
     }

     for (i = 0; i < n; i++) d[i] = 1e16;

     d[0] = 0;

     q.push(make_pair(0, 0));

     while (q.empty() == false) {
	  long long min = -q.top().first;
	  int num = q.top().second;

	  q.pop();

	  if (f[num] == 1) continue;

	  if (num == n - 1) break;

	  f[num] = 1;

	  for (j = 0; j < v[num].size(); j++) {
	       if (d[num] + v[num][j].second < d[v[num][j].first]) {
		    d[v[num][j].first] = d[num] + v[num][j].second;
		    p[v[num][j].first] = num;
		    q.push(make_pair(-d[v[num][j].first], v[num][j].first));
	       }
	  }
     }

     if (d[n - 1] == 1e16) {
	  puts("-1");
     } else {
	  vector <int> w;
	  int c = n - 1;

	  while (c) {
	       w.push_back(c + 1);

	       c = p[c];
	  }

	  w.push_back(1);

	  for (i = 0; i < w.size(); i++) {
	       if (i > 0) putchar(' ');

	       printf("%d", w[w.size() - i - 1]);
	  }

	  puts("");
     }

     return 0;
}