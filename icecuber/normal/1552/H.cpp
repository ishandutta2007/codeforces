#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

array<int,2> check(vector<array<int,2>> wh, int left) {
  if (left == 0) return {int(wh.size() <= 1),-1};

  for (int k = 2; k <= 200; k++) {
    map<int,vector<array<int,2>>> m;
    for (auto [w,h] : wh) {
      m[w*(h/k)].push_back({w,h});  
      if (h%k)
        m[w*((h+k-1)/k)].push_back({w,h});  
    }
    int ok = 1;
    for (auto [r,l] : m) {
      if (!check(l, left-1)[0]) {
        ok = 0;
        break;
      }
    }
    if (ok) return {1,k};
  }
  return {0,-1};
}

int query(int k) {
  cout << "? " << (200+k-1)/k*200 << endl;
  int c = 0;
  for (int i = 1; i <= 200; i += k)
    for (int j = 1; j <= 200; j++)
      cout << i << ' ' << j << ' ', c++;
  cout << endl;
  assert(c == (200+k-1)/k*200);
  int ans;
  cin >> ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  if (0) {
    for (int A = 1; A <= 200*200; A++) {
      vector<array<int,2>> wh;
      for (int w = 1; w <= 200; w++) 
        if (A%w == 0 && A/w <= 200) wh.push_back({w,A/w});
      if (!check(wh,3)[0]) {
        cout << A << endl;
      }
    }
  }

  int A = query(1);
  vector<array<int,2>> wh;
  for (int w = 1; w <= 200; w++) 
    if (A%w == 0 && A/w <= 200) wh.push_back({w,A/w});

  int left = 3;
  while (wh.size() > 1) {
    assert(left);
    int k = check(wh,left)[1];
    int S = query(k);
    vector<array<int,2>> nwh;
    for (auto [w,h] : wh)
      if (w*(h/k) == S || w*((h+k-1)/k) == S)
        nwh.push_back({w,h});
    wh = nwh;
    left--;
  }
  cout << "! " << (wh[0][0]+wh[0][1]-2)*2 << endl;

}