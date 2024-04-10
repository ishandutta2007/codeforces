#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main()
{
     int n, s, i;
     vector <pair<int, int> > v;
     priority_queue <pair<int, int> > q;

     scanf("%d %d", &n, &s);

     for (i = 0; i < n; i++) {
	  int x;

	  scanf("%d", &x);

	  if (x != 0) q.push(make_pair(x, i + 1));
     }

     if (s % 2 == 1) {
	  puts("No");

	  return 0;
     }

     while (!q.empty()) {
	  vector <pair<int, int> > w;
	  pair<int, int> p = q.top();

	  q.pop();

	  if (q.size() < p.first) {
	       puts("No");

	       return 0;
	  }

	  for (i = 0; i < p.first; i++) {
	       pair <int, int> tmp = q.top();

	       q.pop();

	       tmp.first--;

	       v.push_back(make_pair(p.second, tmp.second));

	       w.push_back(tmp);
	  }

	  for (i = 0; i < w.size(); i++) q.push(w[i]);
     }

     puts("Yes");

     printf("%d\n", v.size());

     for (i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);

     return 0;
}