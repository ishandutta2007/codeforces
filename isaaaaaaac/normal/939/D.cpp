#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 5;

char a[N], b[N];
int G[100][100], vis[100];
vector <pair <int, int> > ans;

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (int i = 1; i <= n; i ++)
    if (a[i] != b[i]) G[a[i] - 'a'][b[i] - 'a'] = G[b[i] - 'a'][a[i] - 'a'] = 1;
  for (int k = 0; k < 26; k ++)
    for (int i = 0; i < 26; i ++)
      for (int j = 0; j < 26; j ++) G[i][j] |= G[i][k] & G[k][j];
  for (int i = 0; i < 26; i ++)
    if (!vis[i]) {
      vis[i] = 1;
      for (int j = i + 1; j < 26; j ++)
        if (G[i][j]) {
          vis[j] = 1;
          ans.push_back(make_pair(i, j));
        }
    }
  cout << ans.size() << endl;
  for (auto i : ans) printf("%c %c\n", i.first + 'a', i.second + 'a');
  return 0;
}