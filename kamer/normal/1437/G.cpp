#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Node {
  vector<int> children;
  int parent = 0;
  int suffix = 0;
  int dict_suffix = 0;
  int parent_char = -1;
  bool in_dict = false;

  map<int, int> suspicions;
  map<int, unordered_set<int>> rev_suspicions;

  Node() : children(26, 0) {}
};

vector<Node> automaton(1);

inline int charIndex(char c) {
  return c - 'a';
}

void setSuspicion(int node, int index, int suspicion) {
  int old_suspicion = -1;
  if (automaton[node].suspicions.find(index) != automaton[node].suspicions.end()) {
    old_suspicion = automaton[node].suspicions.at(index);
  }
  if (old_suspicion == suspicion) return;
  automaton[node].suspicions[index] = suspicion;
  automaton[node].rev_suspicions[suspicion].insert(index);
  if (old_suspicion != -1) {
    automaton[node].rev_suspicions[old_suspicion].erase(index);
    if (automaton[node].rev_suspicions[old_suspicion].empty()) {
      automaton[node].rev_suspicions.erase(old_suspicion);
    }
  }
}

int getNodeMaxSuspicion(int node) {
  if (automaton[node].rev_suspicions.empty()) {
    return -1;
  }

  auto it = automaton[node].rev_suspicions.end();
  while (it != automaton[node].rev_suspicions.begin()) {
    it--;
    if (it->second.empty()) {
      automaton[node].rev_suspicions.erase(it->first);
    } else {
      return it->first;
    }
  }
}

int getNodeMaxSuspicionNaive(int node) {
  int res = -1;
  for (auto [index, suspicion] : automaton[node].suspicions) {
    res = max(res, suspicion);
  }
  return res;
}

int addString(string &s, int index, int suspicion) {
  int current_node = 0;
  for (auto c : s) {
    if (automaton[current_node].children[charIndex(c)] == 0) {
      int new_node_index = automaton.size();
      automaton.push_back(Node {});
      automaton[current_node].children[charIndex(c)] = new_node_index;
      automaton[new_node_index].parent = current_node;
      automaton[new_node_index].parent_char = charIndex(c);
    }
    current_node = automaton[current_node].children[charIndex(c)];
  }

  automaton[current_node].in_dict = true;

  setSuspicion(current_node, index, suspicion);

  return current_node;
}

void setSuffixes() {
  // Note: important to do BFS and not DFS
  queue<int> node_indices;
  node_indices.push(0);
  while (!node_indices.empty()) {
    int node = node_indices.front();
    node_indices.pop();

    for (auto child : automaton[node].children) {
      if (child != 0) {
        node_indices.push(child);
      }
    }

    if (automaton[node].parent == 0) continue;
    int char_index = automaton[node].parent_char;
    int parent = automaton[node].parent;
    while (parent > 0 && automaton[automaton[parent].suffix].children[char_index] == 0) {
      parent = automaton[parent].suffix;
    }
    automaton[node].suffix = automaton[automaton[parent].suffix].children[char_index];
  }
}

void setDictSuffixes() {
  // Note: importan to do BFS and not DFS
  queue<int> node_indices;
  node_indices.push(0);
  while (!node_indices.empty()) {
    int node = node_indices.front();
    node_indices.pop();

    for (auto child : automaton[node].children) {
      if (child != 0) {
        node_indices.push(child);
      }
    }

    if (automaton[automaton[node].suffix].in_dict) {
      automaton[node].dict_suffix = automaton[node].suffix;
    } else {
      automaton[node].dict_suffix = automaton[automaton[node].suffix].dict_suffix;
    }
  }
}

// Assumes string has already been inserted into automaton
void changeSuspicion(string &s, int index, int new_suspicion) {
  int current_node = 0;
  for (auto c : s) {
    current_node = automaton[current_node].children[charIndex(c)];
  }
  setSuspicion(current_node, index, new_suspicion);
}

void changeSuspicion(int node, int index, int new_suspicion) {
  setSuspicion(node, index, new_suspicion);
}

string getNodeString(int node) {
  int current_node = node;
  string s;
  while (current_node != 0) {
    s.push_back(automaton[current_node].parent_char + 'a');
    current_node = automaton[current_node].parent;
  }
  reverse(s.begin(), s.end());
  return s;
}

int getMaxSuspicion(string &s) {
  int current_node = 0;
  int res = -1;
  unordered_set<int> analyzed_nodes;
  analyzed_nodes.reserve(128);
  analyzed_nodes.max_load_factor(0.25);
  for (auto c : s) {
    while (current_node > 0 && automaton[current_node].children[charIndex(c)] == 0) {
      current_node = automaton[current_node].suffix;
    }

    current_node = automaton[current_node].children[charIndex(c)];
    int parent_node = current_node;
    while (analyzed_nodes.find(parent_node) == analyzed_nodes.end()) {
      analyzed_nodes.insert(parent_node);
      res = max(res, getNodeMaxSuspicion(parent_node));
      parent_node = automaton[parent_node].dict_suffix;
    }
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> dict(n);
  vector<int> automaton_index(n);
  for (int i = 0; i < n; i++) {
    cin >> dict[i];
    automaton_index[i] = addString(dict[i], i, 0);
  }
  setSuffixes();
  setDictSuffixes();
  int indexD = 0;
  for (int i = 0; i < m; i++) {
    int req;
    cin >> req;
    if (req == 1) {
      int index, new_suspicion;
      cin >> index >> new_suspicion;
      index--;
      changeSuspicion(automaton_index[index], index, new_suspicion);
    } else if (req == 2) {
      string s;
      cin >> s;
      indexD++;
      cout << getMaxSuspicion(s) << "\n";
    }
  }
}