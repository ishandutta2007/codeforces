#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

vector <int> g[600000];
int m[600000];
int f[600000];

int dfs(int v)
{
  int i;

  f[v] = 1;

  for (i = 0; i < g[v].size(); i++) {
    int x = g[v][i], y = m[x];

    if (y < 0 || (f[y] == 0 && dfs(y) == 1)) {
      m[v] = x;
      m[x] = v;

      return 1;
    }
  }

  return 0;
}

int main()
{
  int n, sum = 0, i, j, k;
  char s[200][11];
  int a[200];
  FILE *fp1, *fp2;

  fp1 = fopen("input.txt", "r");
  fp2 = fopen("output.txt", "w");

  for (i = 0; i < 600000; i++) m[i] = -1;

  fscanf(fp1, "%d", &n);

  for (i = 0; i < n; i++) {
    fscanf(fp1, "%s", s[i]);

    a[i] = strlen(s[i]);
  }

  for (i = 0; i < n; i++) {
    for (j = 1; j < (1 << a[i]); j++) {
      int p = 0, x = 0;
      char c[10];

      for (k = a[i] - 1; k >= 0; k--) {
	if ((j >> k) & 1) {
	  c[p++] = s[i][a[i] - k - 1];
	}
      }

      if (p > 4) continue;

      for (k = 0; k < p; k++) {
	x *= 27;
	x += c[k] - 'a' + 1;
      }

      g[i].push_back(x + n);
      g[x + n].push_back(i);
    }
  }

  for (i = 0; i < n; i++) {
    if (m[i] < 0) {
      memset(f, 0, sizeof(f));

      if (dfs(i) == 1) sum++;
    }
  }

  if (sum < n) {
    fprintf(fp2, "-1\n");
  } else {
    for (i = 0; i < n; i++) {
      int p = 0;
      char c[5];

      m[i] -= n;

      while (m[i] > 0) {
	c[p++] = (m[i] - 1) % 27 + 'a';

	m[i] /= 27;
      }

      for (j = 0; j < p / 2; j++) {
	int tmp = c[j];
	c[j] = c[p - j - 1];
	c[p - j - 1] = tmp;
      }

      c[p] = '\0';

      fprintf(fp2, "%s\n", c);
    }
  }

  fclose(fp1);
  fclose(fp2);

  return 0;
}