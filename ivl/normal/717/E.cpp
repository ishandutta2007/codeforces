#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 200010;
int n;
int V[MAXN];
int good[MAXN];
vector<int> E[MAXN];
vector<int> sol;

bool rekP(int curr, int par) {
  good[curr] = 1;
  for (int i = 0; i < E[curr].size(); i++) {
    int next = E[curr][i];
    if (next == par) continue;
    rekP(next, curr);
    if (!good[next]) good[curr] = 0;
  }
  if (V[curr] == -1) good[curr] = 0;
  return good[curr];
}

void rek(int curr, int par) {
  sol.push_back(curr);
  if (par != 0) V[curr] *= -1;
  for (int i = 0; i < E[curr].size(); i++) {
    int next = E[curr][i];
    if (next == par) continue;
    if (good[next]) continue;
    rek(next, curr);
    V[curr] *= -1;
    sol.push_back(curr);
    if (V[next] == -1) {
      V[next] *= -1;
      V[curr] *= -1;
      sol.push_back(next);
      sol.push_back(curr);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", V+i);
  }
  for (int i = 0; i < n-1; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    E[l].push_back(r);
    E[r].push_back(l);
  }
  if (rekP(1, 0)) {
    printf("1\n");
    return 0;
  }
  rek(1, 0);

  if (V[1] == -1) {
    sol.push_back(E[1][0]);
    sol.push_back(1);
    sol.push_back(E[1][0]);
  }

  for (int i = 0; i < sol.size(); i++) {
    printf("%d ", sol[i]);
  }
  printf("\n");

  return 0;
}