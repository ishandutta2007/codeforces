#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b, int c)
{
     int m = a;
     if (m < b) m = b;
     if (m < c) m = c;

     return m;
}

int min(int a, int b, int c)
{
     int m = a;
     if (m > b) m = b;
     if (m > c) m = c;

     return m;
}

int main()
{
     int n, a, b, c, m = 1000000000, num = 0, i, j, k;
     int d[7][7] = {0};
     char s1[20], s2[20];
     char s[7][20] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};

     scanf("%d", &n);

     for (i = 0; i < n; i++) {
	  scanf("%s %*s %s", s1, s2);

	  for (j = 0; j < 7; j++) {
	       if (strcmp(s1, s[j]) == 0) break;
	  }

	  for (k = 0; k < 7; k++) {
	       if (strcmp(s2, s[k]) == 0) break;
	  }

	  d[j][k] = 1;
     }

     scanf("%d %d %d", &a, &b, &c);

     for (i = 0; i < 2187; i++) {
	  int p[7], q[3] = {0};
	  int t = i, l = 0;

	  for (j = 0; j < 7; j++) {
	       p[j] = t % 3;
	       q[t % 3]++;

	       t /= 3;
	  }

	  if (q[0] * q[1] * q[2] == 0) continue;

	  for (j = 0; j < 7; j++) {
	       for (k = 0; k < 7; k++) {
		    if (d[j][k] == 1 && p[j] == p[k]) l++;
	       }
	  }

	  sort(q, q + 3);

	  do {
	       int x = a / q[0], y = b / q[1], z = c / q[2];

	       int v = max(x, y, z) - min(x, y, z);

	       if (v < m) {
		    m = v; num = l;
	       } else if (v == m && num < l) {
		    num = l;
	       }
	  } while (next_permutation(q, q + 3));
     }

     printf("%d %d\n", m, num);

     return 0;
}