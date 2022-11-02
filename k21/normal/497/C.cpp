#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 100100;

int N, M;
ll A[MAXN];
ll B[MAXN];
ll C[MAXN];
ll D[MAXN];
int K[MAXN];

vector<pair<ll, pair<int, int>>> events;

// D, id
set<pair<ll, int>> waitingActors;

int answer[MAXN];

int main() {
	scanf("%d", &N);
  REP(i,N) {
    int a, b;
    scanf("%d%d", &a, &b);
    A[i] = a; B[i] = b;
  }
	scanf("%d", &M);
  REP(i,M) {
    int c, d, k;
    scanf("%d%d%d", &c, &d, &k);
    C[i] = c; D[i] = d; K[i] = k;
  }
  
  REP(i,N) A[i] *= 3;
  REP(i,N) B[i] *= 3;
  REP(i,M) C[i] = 3*C[i]-1;
  REP(i,M) D[i] = 3*D[i]+1;

  REP(i,N) events.push_back({A[i], {i, 0}});
  REP(i,M) events.push_back({C[i], {i, 2}});
  REP(i,M) events.push_back({D[i], {i, 3}});

  sort(events.begin(), events.end());
  REP(ei,(int)events.size()) {
    ll time;
    int idx, type;
    time = events[ei].first;
    idx = events[ei].second.first;
    type = events[ei].second.second;
    auto it = waitingActors.begin();
    while (it != waitingActors.end() && it->first < time) {
      waitingActors.erase(it);
      it = waitingActors.begin();
    }
    if (type == 0) {
      auto it = waitingActors.lower_bound({B[idx], -1});
      if (it == waitingActors.end()) {
        printf("NO\n");
        return 0;
      }
      answer[idx] = it->second;
      if (--K[it->second] == 0) {
        waitingActors.erase(it);
      }
    } else if (type == 2) {
      waitingActors.insert({D[idx], idx});
    }
  }
  
  printf("YES\n");
  REP(i,N) printf("%d%c", answer[i]+1, i==N-1 ? '\n' : ' ');
	return 0;
}