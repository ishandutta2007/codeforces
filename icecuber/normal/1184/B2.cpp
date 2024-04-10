#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[100][100];
int adj[1000][1000];

int shipi[1000], shipa[1000], shipf[1000];
int basei[1000], based[1000];

int done[1000], matching[1000];
int bases;
int match(int p) {
  for (int i = 0; i < bases; i++) {
    if (adj[p][i] && !done[i]++ && (matching[i] == -1 || match(matching[i]))) {
      matching[i] = p;
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dist[i][j] = 1e9;
  dist[0][0] = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    dist[a][b] = dist[b][a] = 1;
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
  int ships;
  ll attacked_cost, fake_cost;
  cin >> ships >> bases >> attacked_cost >> fake_cost;
  for (int i = 0; i < ships; i++) {
    cin >> shipi[i] >> shipa[i] >> shipf[i];
    shipi[i]--;
  }
  for (int i = 0; i < bases; i++) {
    cin >> basei[i] >> based[i];
    basei[i]--;
  }
  for (int i = 0; i < ships; i++) {
    for (int j = 0; j < bases; j++) {
      if (dist[shipi[i]][basei[j]] <= shipf[i] && based[j] <= shipa[i]) {
	adj[i][j] = 1;
      }
    }
  }

  int matchings = 0;
  fill_n(matching, bases, -1);
  for (int i = 0; i < ships; i++) {
    fill_n(done, bases, 0);
    matchings += match(i);
  }
  cout << min(attacked_cost*matchings, fake_cost*ships) << endl;
}