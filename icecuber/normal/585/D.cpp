#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[25], b[25], c[25];

void rec_add(int i, int n, int db,int dc,int sa, map<pair<int,int>,pair<int,string>>&m, string&path) {
  if (i == n) {
    //cout << path;
    //cout << sa << ' ' << sa+db << ' ' << sa+dc << endl;
    auto it = m.find({db,dc});
    if (it == m.end() || sa > it->second.first)
      m[{db,dc}] = make_pair(sa,path);
    return;
  }
  for (int j = 0; j < 3; j++) {
    int ndb = db, ndc = dc, nsa = sa;
    string npath = path;
    if (j != 0) {
      nsa += a[i];
      ndb -= a[i];
      ndc -= a[i];
    }
    if (j != 1) {
      ndb += b[i];
    }
    if (j != 2) {
      ndc += c[i];
    }
    npath += char(j);
    rec_add(i+1,n,ndb,ndc,nsa,m,npath);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int na = n/2, nb = n-na;

  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> c[i];

  map<pair<int,int>,pair<int,string>> ma, mb;
  {
    string path;
    rec_add(0,na,0,0,0,ma,path);
    rec_add(na,n,0,0,0,mb,path);
  }

  int best_score = -1e9;
  string path;
  for (auto p : ma) {
    pair<int,int> q = {-p.first.first, -p.first.second};
    if (!mb.count(q)) continue;
    auto here = p.second;
    auto match = mb[q];
    int score = here.first+match.first;
    if (score > best_score) {
      best_score = score;
      //cout << here.second << ' ' << here.first << ' ' << here.first+p.first.first << ' ' << here.first+p.first.second << endl;
      //cout << match.second << ' ' << match.first << ' ' << match.first+p.first.first << ' ' << match.first+p.first.second << endl;
      //cout << endl;
      path = here.second+match.second;
    }
  }
  if (best_score == -1e9) {
    cout << "Impossible" << endl;
    return 0;
  }
  for (char c : path) {
    for (int j : {0,1,2}) {
      if (j != c) cout << "LMW"[j];
    }
    cout << '\n';
  }
}