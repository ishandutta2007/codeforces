//============================================================================
// Name        : C.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <numeric>
#include <functional>
#include <limits>
using namespace std;

int main() {
  int n, k;
  ios::sync_with_stdio(false);
  vector<int> rooms;
  cin >> n >>  k;
  string s;
  cin >> s;
  for (int i =0; i < n; ++i) {
    if (s[i] == '0') {
      rooms.push_back(i);
    }
  }
  set<int> cur;
  auto getCurAns = [&]() {
    auto it1 = cur.begin(), it2 = cur.end();
    --it2;
    auto it3 = cur.lower_bound((*it1 + *it2 + 1) / 2);
    int result = numeric_limits<int>::max();
    if (it3 != cur.end())
      result = max(*it2 - *it3, *it3 - *it1);
    if (it3 != cur.begin()) {
      --it3;
      result = min(result, max(*it2 - *it3, *it3 - *it1));
    }
    return result;
  };
  ++k;
  for (int i = 0; i < k; ++i)
    cur.insert(rooms[i]);
  int result = getCurAns();
  for (int i = 0; i + k < (int)rooms.size(); ++i) {
    cur.erase(rooms[i]);
    cur.insert(rooms[i+k]);
    result = min(result, getCurAns());
  }
  cout << result << endl;
  return 0;
}