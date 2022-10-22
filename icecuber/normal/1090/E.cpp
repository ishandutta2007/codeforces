#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int hashorse[64];

int done[64], par[64];
vector<int> findpath(int s, int e) {
  for (int i = 0; i < 64; i++) done[i] = 0;
  queue<int> q;
  q.push(s);
  done[s] = 1;
  while (q.size()) {
    int p = q.front();
    q.pop();
    int x = p&7, y = p>>3;
    for (int i = 0; i < 64; i++) {
      int nx = i&7, ny = i>>3;
      int dx = x-nx, dy = y-ny;
      if (dx*dx+dy*dy == 5 && !done[i]++) {
	par[i] = p;
	q.push(i);
      }
    }
  }
  vector<int> path;
  int p = e;
  while (p != s) {
    path.push_back(p);
    p = par[p];
  }
  path.push_back(p);
  reverse(path.begin(), path.end());
  return path;
}

vector<string> ans;
void domove(int i, int j) {
  //cout << i%8 << ' ' << i/8 << " to ";
  //cout << j%8 << ' ' << j/8 << endl;
  assert(hashorse[i]);
  assert(!hashorse[j]);
  swap(hashorse[i], hashorse[j]);
  string s;
  s += char(i%8+'a');
  s += char(i/8+'1');
  s += '-';
  s += char(j%8+'a');
  s += char(j/8+'1');
  ans.push_back(s);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    hashorse[(s[1]-'1')*8+(s[0]-'a')] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (hashorse[i]) continue;
    int s;
    for (int j = n; ; j++) {
      if (hashorse[j]) {
	s = j;
	break;
      }
    }
    vector<int> path = findpath(s, i);
    //for (int i : path) cout << i%8 << ' ' << i/8 << endl;
    for (int j = 0; j+1 < path.size(); j++) {
      int k = j+1;
      while (hashorse[path[k]]) k++;
      for (int l = k; l > j; l--)
	domove(path[l-1], path[l]);
      j = k-1;
    }
  }
  //for (int i = 0; i < 64; i++) cout << hashorse[i];
  //cout << endl;
  cout << ans.size() << '\n';
  for (string s : ans) cout << s << '\n';
}