#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int> > q;
int n, e[500233], m, a = 1;
  
int main() {
  scanf("%d", &n);
  while (n--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x; ++m;
      scanf("%d", &x);
      q.push(make_pair(x, -m));
    } else if (t == 2) {
      while (e[a]) a++;
      e[a] = 1;
      printf("%d ", a);
    } else {
      while (e[-q.top().second]) q.pop();
      e[-q.top().second] = 1;
      printf("%d ", -q.top().second);
      q.pop();
    }
  }
}