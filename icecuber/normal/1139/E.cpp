#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int pot[5000], club[5000];

map<int,int> node[5000];
int done[5000], matching[5000];

int target_pot;

int matchedu[5000];

int match(int u) {
  for (auto&p : node[u]) {
    int v = p.first;
    if (v < target_pot && !done[v]++ && (matching[v] == -1 || match(matching[v]))) {
      matching[v] = u;
      matchedu[u] = 1;
      return 1;
    }
  }
  return 0;
}

int n;
int match() {
  fill_n(matchedu, n, 0);
  for (int v = 0; v < target_pot; v++)
    if (matching[v] != -1)
      matchedu[matching[v]] = 1;

  int newmatch = 1;
  while (newmatch) {
    newmatch = 0;
    fill_n(done, target_pot, 0);
    for (int u = 0; u < n; u++)
      if (!matchedu[u])
	newmatch += match(u);
  }
  int matched = 0;
  for (int v = 0; v < target_pot; v++)
    matched += matching[v] != -1;
  return matched;
}


int main() {
  int students;
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> students >> n;
  for (int i = 0; i < students; i++)
    cin >> pot[i];
  for (int i = 0; i < students; i++) {
    cin >> club[i];
    club[i]--;
    node[club[i]][pot[i]]++;
  }
  int pass = 0, fail = n+1;
  while (fail-pass > 1) {
    target_pot = pass+fail>>1;
    fill_n(matching, target_pot, -1);
    int matched = match();
    if (matched >= target_pot) pass = target_pot;
    else fail = target_pot;
  }

  target_pot = pass;
  fill_n(matching, target_pot, -1);
  assert(match() == pass);

  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    k--;
    if (!--node[club[k]][pot[k]]) {
      node[club[k]].erase(pot[k]);
      if (matching[pot[k]] == club[k]) {
	matching[pot[k]] = -1;
	while (1) {
	  int matched = match();
	  if (matched < target_pot) {
	    target_pot--;
	  } else break;
	}
      }
    }
    /*for (int i = 0; i < target_pot; i++) {
      cout << matching[i] << ' ';
    }
    cout << endl;*/
    cout << target_pot << endl;
  }
}