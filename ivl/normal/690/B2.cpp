#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define pb push_back
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pt;

const int MAX = 1000;

int N;
char A[MAX][MAX];

int ccw(pt a, pt b, pt c) {
  return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
}

vector<pt> convex_hull(vector<pt> P) {
  sort(P.begin(), P.end());
  
  vector<pt> H;
  REP(step, 2) {
    int start = (int)H.size();
    for (auto p : P) {
      while ((int)H.size() >= start + 2 && ccw(H[H.size()-2], H.back(), p) >= 0)
        H.pop_back();
      H.push_back(p);
    }
    
    reverse(P.begin(), P.end());
    H.pop_back();
  }
  
  return H;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  
  while ((cin >> N) && N) {
    REP(i, N) cin >> A[i];
    REP(i, N) REP(j, N) A[i][j] -= '0';
    vector<pt> P;
    
    REP(i, N-1) REP(j, N-1) {
      if (A[i][j] && A[i][j+1] && A[i+1][j] && A[i+1][j+1])
        P.pb({j+1, N-i-1});
    }
    
    sort(P.begin(), P.end());
    P = convex_hull(P);
    
    cout << (int)P.size() << endl;
    for (auto p : P) cout << p.x << " " << p.y << endl;
  }

  
  

  return 0; 
}