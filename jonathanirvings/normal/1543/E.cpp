#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> adj;
vector<int> P, P_inv;

vector<int> get_distance(int S) {
  vector<int> distance(1 << N, INT_MAX);
  distance[S] = 0;
  queue<int> q;
  q.push(S);
  while (!q.empty()) {
    int U = q.front();
    q.pop();
    for (int V : adj[U]) {
      if (distance[U] + 1 < distance[V]) {
        distance[V] = distance[U] + 1;
        q.push(V);
      }
    }
  }
  return distance;
}

void setP(int ix, int val) {
  P[ix] = val;
  P_inv[val] = ix;
}

void recurse(int M, unordered_set<int> nodes) {
  assert(nodes.size() == (1 << M));
  if (M == 0) {
    setP(0, *nodes.begin());
    return;
  }
  vector<int> distance_from_start = get_distance(*nodes.begin());
  int target = INT_MAX;
  for (int node : nodes) {
    if (distance_from_start[node] == M - 1) {
      target = node;
      break;
    }
  }
  assert(target != INT_MAX);
  vector<int> distance_to_target = get_distance(target);

  unordered_set<int> first_half, second_half;
  for (int node : nodes) {
    if (distance_from_start[node] + distance_to_target[node] == M - 1) {
      first_half.insert(node);
    } else {
      second_half.insert(node);
    }
  }

  recurse(M - 1, first_half);
  for (int node : second_half) {
    for (int neigh : adj[node]) {
      if (first_half.count(neigh)) {
        setP(P_inv[neigh] | (1 << (M - 1)), node);
        break;
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    adj.clear();
    adj.resize(1 << N);
    for (int i = 0; i < N * (1 << (N - 1)); ++i) {
      int U, V;
      scanf("%d %d", &U, &V);
      adj[U].push_back(V);
      adj[V].push_back(U);
    }
    P.resize(1 << N);
    P_inv.resize(1 << N);

    vector<int> all_nodes(1 << N);
    iota(all_nodes.begin(), all_nodes.end(), 0);
    recurse(N, unordered_set<int>(all_nodes.begin(), all_nodes.end()));

    for (int i = 0; i < (1 << N); ++i) {
      printf("%d%c", P[i], " \n"[i == (1 << N) - 1]);
    }

    if ((N & -N) == N) {
      vector<int> colors;
      colors.push_back(0);
      for (int i = 1; i < (1 << N); ++i) {
        for (int j = 0; j < N; ++j) {
          if (i & (1 << j)) {
            colors.push_back(colors[i ^ (1 << j)] ^ j);
            break;
          }
        }
      }

      for (int i = 0; i < (1 << N); ++i) {
        printf("%d%c", colors[P_inv[i]], " \n"[i == (1 << N) - 1]);
      }
    } else {
      puts("-1");
    }
  }
}