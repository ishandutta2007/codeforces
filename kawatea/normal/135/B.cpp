#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dist(int x1, int y1, int x2, int y2)
{
     return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
     int i, j;
     int x[8], y[8];

     for (i = 0; i < 8; i++) scanf("%d %d", &x[i], &y[i]);

     for (i = 0; i < (1 << 8); i++) {
	  int f1 = 0, f2 = 0;
	  vector <int> v, w;

	  for (j = 0; j < 8; j++) {
	       if ((i >> j) & 1) {
		    v.push_back(j);
	       } else {
		    w.push_back(j);
	       }
	  }

	  if (v.size() != 4) continue;

	  do {
	       int p = dist(x[v[0]], y[v[0]], x[v[3]], y[v[3]]);
	       int q;

	       for (j = 0; j < 3; j++) {
		    q = dist(x[v[j]], y[v[j]], x[v[j + 1]], y[v[j + 1]]);

		    if (p != q) break;
	       }

	       if (j == 3) {
		    p = dist(x[v[0]], y[v[0]], x[v[2]], y[v[2]]);
		    q = dist(x[v[1]], y[v[1]], x[v[3]], y[v[3]]);

		    if (p == q && p > 0) {
			 f1 = 1;

			 break;
		    }
	       }
	  } while (next_permutation(v.begin(), v.end()));

	  do {
	       int p = dist(x[w[0]], y[w[0]], x[w[1]], y[w[1]]);
	       int q = dist(x[w[2]], y[w[2]], x[w[3]], y[w[3]]);

	       if (p == q && p > 0) {
		    p = dist(x[w[0]], y[w[0]], x[w[3]], y[w[3]]);
		    q = dist(x[w[1]], y[w[1]], x[w[2]], y[w[2]]);

		    if (p == q && p > 0) {
			 p = dist(x[w[0]], y[w[0]], x[w[2]], y[w[2]]);
			 q = dist(x[w[1]], y[w[1]], x[w[3]], y[w[3]]);

			 if (p == q && p > 0) {
			      f2 = 1;

			      break;
			 }
		    }
	       }
	  } while (next_permutation(w.begin(), w.end()));

	  if (f1 == 1 && f2 == 1) {
	       puts("YES");

	       for (j = 0; j < 4; j++) {
		    if (j > 0) putchar(' ');

		    printf("%d", v[j] + 1);
	       }
	       puts("");

	       for (j = 0; j < 4; j++) {
		    if (j > 0) putchar(' ');

		    printf("%d", w[j] + 1);
	       }
	       puts("");

	       return 0;
	  }
     }

     puts("NO");

     return 0;
}