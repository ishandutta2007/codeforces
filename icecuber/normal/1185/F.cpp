#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int happy[1<<9];
int pizza_i[1<<9][2], pizza_cost[1<<9][2];
pair<int,int> pizza2_i[1<<9];
int pizza2_cost[1<<9];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    int pref = 0;
    while (k--) {
      int i;
      cin >> i;
      pref |= 1<<i-1;
    }
    happy[pref]++;
  }
  for (int j = 0; j < 9; j++)
    for (int i = 0; i < 1<<9; i++)
      if (i>>j&1)
	happy[i] += happy[i^1<<j];
  int inf = 1e9+5;
  fill_n((int*)pizza_cost, 2<<9, inf);
  fill_n(pizza2_cost, 1<<9, inf*2);
  for (int i = 0; i < m; i++) {
    int cost, k;
    cin >> cost >> k;
    int has = 0;
    while (k--) {
      int i;
      cin >> i;
      has |= 1<<i-1;
    }
    if (pizza_cost[has][0] > cost) {
      pizza_cost[has][1] = pizza_cost[has][0];
      pizza_i[has][1] = pizza_i[has][0];
      pizza_cost[has][0] = cost;
      pizza_i[has][0] = i+1;
    } else if (pizza_cost[has][1] > cost) {
      pizza_cost[has][1] = cost;
      pizza_i[has][1] = i+1;
    }
  }
  for (int a = 0; a < 1<<9; a++)
    for (int b = 0; b < 1<<9; b++)
      if (pizza_i[a][0] && pizza_i[b][a==b] &&
	  pizza_cost[a][0]+pizza_cost[b][a==b] < pizza2_cost[a|b]) {
	pizza2_cost[a|b] = pizza_cost[a][0]+pizza_cost[b][a==b];
	pizza2_i[a|b] = {pizza_i[a][0],pizza_i[b][a==b]};
      }
  int max_happy = -1, min_cost;
  pair<int,int> choice;
  for (int i = 0; i < 1<<9; i++) {
    if (!pizza2_i[i].first) continue;
    if (happy[i] > max_happy) {
      max_happy = happy[i];
      min_cost = pizza2_cost[i];
      choice = pizza2_i[i];
    } else if (happy[i] == max_happy && pizza2_cost[i] < min_cost) {
      min_cost = pizza2_cost[i];
      choice = pizza2_i[i];
    }
  }
  cout << choice.first << ' ' << choice.second << endl;
}