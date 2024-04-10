#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int, int> > v[100000];
int d[100000];

int main()
{
     int n, m, s, l, sum = 0, i, j;
     priority_queue <pair<int, int> > q;

     scanf("%d %d %d", &n, &m, &s);

     for (i = 0; i < m; i++) {
	  int x, y, z;

	  scanf("%d %d %d", &x, &y, &z);

	  x--;
	  y--;

	  v[x].push_back(make_pair(y, z));
	  v[y].push_back(make_pair(x, z));
     }

     scanf("%d", &l);

     for (i = 0; i < n; i++) d[i] = 1e9;

     q.push(make_pair(0, --s));

     while (!q.empty()) {
	  pair <int, int> p = q.top();

	  q.pop();

	  if (d[p.second] < 1e9) continue;

	  d[p.second] = -p.first;

	  for (i = 0; i < v[p.second].size(); i++) {
	       if (d[v[p.second][i].first] == 1e9) {
		    q.push(make_pair(p.first - v[p.second][i].second, v[p.second][i].first));
	       }
	  }
     }

     for (i = 0; i < n; i++) {
	  for (j = 0; j < v[i].size(); j++) {
	       int x = v[i][j].first;

	       if (d[i] == d[x]) {
		    if (d[i] < l) {
			 if (2 * d[i] + v[i][j].second == 2 * l) {
			      sum++;
			 } else if (2 * d[i] + v[i][j].second > 2 * l) {
			      sum += 2;
			 }
		    }
	       } else if (d[i] < d[x]) {
		    if (d[i] < l) {
			 if (d[x] > l) {
			      sum++;
			 } else if (d[x] < l) {
			      if (d[i] + d[x] + v[i][j].second == 2 * l) {
				   sum++;
			      } else if (d[i] + d[x] + v[i][j].second > 2 * l) {
				   sum += 2;
			      }
			 } else {
			      if (d[i] + v[i][j].second > l) sum++;
			 }
		    }
	       } else {
		    if (d[x] < l) {
			 if (d[i] > l) {
			      sum++;
			 } else if (d[i] < l) {
			      if (d[i] + d[x] + v[i][j].second == 2 * l) {
				   sum++;
			      } else if (d[i] + d[x] + v[i][j].second > 2 * l) {
				   sum += 2;
			      }
			 } else {
			      if (d[x] + v[i][j].second > l) sum++;
			 }
		    }
	       }
	  }
     }

     sum /= 2;

     for (i = 0; i < n; i++) {
	  if (d[i] == l) sum++;
     }

     printf("%d\n", sum);

     return 0;
}