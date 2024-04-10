#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <set>

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)

#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<string> P1 = {"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
		     "h2", "h3", "h4", "h5", "h6", "h7", "h8"};
set<string> S1 = {"a1", "h1", "h8"};

vector<string> P2 = {"a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8",
		     "b8", "b7", "b6", "b5", "b4", "b3", "b2", "b1",
		     "h1", "h2", "h3", "h4", "h5", "h6", "h7", "h8"};
set<string> S2 = {"a1", "a8", "b8", "b1", "h1", "h8"};

vector<string> P3 = {"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
		     "h2", "g2", "f2", "e2", "d2", "c2", "b2", "a2",
		     "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
		     "h4", "g4", "f4", "e4", "d4", "c4", "b4", "a4",
		     "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
		     "h6", "g6", "f6", "e6", "d6", "c6", "b6", "a6",
		     "a7", "b7", "c7", "d7", "e7", "f7",
		     "f8", "e8", "d8", "c8", "b8", "a8", "g8",
		     "g7", "h7", "h8"};
set<string> S3 = {"a1", "h1", "h2", "a2", "a3", "h3", "h4", "a4", "a5",
		     "h5", "h6", "a6", "a7", "f7", "f8",
		     "g8", "g7", "h7", "h8"};

void f(vector<string> all, set<string> important, int N) {
  int M = N - (int)important.size();
  for (auto x: all) {
    if (important.find(x) != important.end()) {
      cout << x << " ";
    }
    else if (M > 0) {
      cout << x << " ";
      M--;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  int N;
  cin>>N;
  N++;

  if (N <= 10) {
    f(P1, S1, N);
  }
  else if (N <= 23) {
    f(P2, S2, N);
  }
  else {
    f(P3, S3, N);
  }
  return 0;
}