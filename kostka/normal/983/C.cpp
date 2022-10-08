//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

//            obs  pie  ile  gdzie
typedef tuple<int, int, int, ll> state;

map <state, int> D;

struct Cmp {
  bool operator()(const state& a, const state& b) {
    return D[a] > D[b];
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <pii> emp(n);
  for(int i=0; i<n; i++) {
    cin >> emp[i].x >> emp[i].y;
  }
  priority_queue <state, vector<state>, Cmp> Q;
  state initial = make_tuple(0, 1, 0, 0);
  Q.push(initial);
  D[initial] = 0;
  int ret = 1e9;
  while(!Q.empty()) {
    state v = Q.top();
    Q.pop();
    if(get<0>(v) == n and get<2>(v) == 0) {
      ret = min(ret, D[v]);
      continue;
    }
    ll eee = (get<3>(v) >> (get<1>(v) * 3)) & 7LL;
    if(eee > 0) {
      // eee = 1;
      auto w = v;
      get<2>(w) -= eee;
      get<3>(w) -= (eee << (get<1>(v) * 3));
      if(D.find(w) == D.end() or D[w] > D[v]+eee) {
        D[w] = D[v]+eee;
        Q.push(w);
      }
      continue;
    }
      for(int d=-1; d<=1; d+=2) {
        state w = v;
        get<1>(w) += d;
        if(not(1 <= get<1>(w) and get<1>(w) <= 9)) continue;
        if(D.find(w) == D.end() or D[w] > D[v]) {
          D[w] = D[v]+1;
          Q.push(w);
        }
      }
      if(get<0>(v) < n and emp[get<0>(v)].x == get<1>(v) and get<2>(v)<4) {
        auto w = v;
        get<3>(w) += (1LL << (emp[get<0>(v)].y * 3));
        get<2>(w)++;
        get<0>(w)++;
        if(D.find(w) == D.end() or D[w] > D[v]) {
          D[w] = D[v]+1;
          Q.push(w);
        }
      }

  }
  cout << ret << "\n";
  return 0;
}