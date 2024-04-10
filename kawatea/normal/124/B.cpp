#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
     int n, k, ans = 1e9, i, j;
     int a[8][8];
     vector <int> v;

     scanf("%d %d", &n, &k);

     for (i = 0; i < n; i++) {
	  for (j = 0; j < k; j++) {
	       scanf("%1d", &a[i][j]);
	  }
     }

     for (i = 0; i < k; i++) v.push_back(i);

     do {
	  int p = 0, q = 1e9;

	  for (i = 0; i < n; i++) {
	       int c = 0;

	       for (j = 0; j < k; j++) {
		    c *= 10;
		    c += a[i][v[j]];
	       }

	       if (c > p) p = c;
	       if (c < q) q = c;
	  }

	  if (p - q < ans) ans = p - q;
     } while (next_permutation(v.begin(), v.end()));

     printf("%d\n", ans);

     return 0;
}