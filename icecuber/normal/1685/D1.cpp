#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int&v : p) cin >> v, v--;
    vector<vector<int>> cycle;
    vector<int> done(n);
    for (int i = 0; i < n; i++) {
      if (done[i]) continue;
      cycle.push_back({});
      int pos = i;
      while (!done[pos]++) {
        cycle.back().push_back(pos);
        pos = p[pos];
      }
    }
    int score = cycle.size()-1;    
    while (cycle.size() > 1) {
      for (int i = 0; i < (int)cycle.size(); i++) {
        for (int j = 0; j < i; j++) {
          for (int a = 0; a < (int)cycle[i].size(); a++) {
            for (int b = 0; b < (int)cycle[j].size(); b++) {
              if (abs(cycle[i][a]-cycle[j][b]) == 1) {
                vector<int> sum;
                for (int c = 0; c < (int)cycle[i].size(); c++) 
                  sum.push_back(cycle[i][(c+a)%(int)cycle[i].size()]);
                for (int c = 0; c < (int)cycle[j].size(); c++) 
                  sum.push_back(cycle[j][(c+b)%(int)cycle[j].size()]);
                cycle.erase(cycle.begin()+i);
                cycle.erase(cycle.begin()+j);
                cycle.push_back(sum);
                goto next;
              }
            }
          }
        }
      }
next:;
    }
    vector<int> ans = cycle[0];
    assert((int)ans.size() == n);
    reverse(ans.begin(), ans.end());
//#warning TODO
    for (int&v : ans) v++;
    for (int&v : ans) cout << v << ' ';
    cout << endl;
    //cout << score*2 << endl;

    int actual = 0;
    for (int i = 0; i < n; i++) {
      actual += abs(ans[i]-(p[ans[(i+1)%n]-1]+1));
    }
    //cout << actual << ' ' << score*2 << ' ' << l << ' ' << r << endl;
    assert(actual == score*2);
  }
}