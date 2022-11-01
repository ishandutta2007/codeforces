#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)

#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 205, MAXS = 4;

tuple<int,int,int,int> odakle[MAX][MAX][MAXS][MAXS];
int dp[MAX][MAX][MAXS][MAXS];

int main(){
  ios_base::sync_with_stdio(false);

  dp[0][0][0][0] = 1;
  REP(b1, MAX) {
    REP(b2, MAX) {
      REP(s1, MAXS-1) {
	REP(s2, MAXS-1) {
	  if (!dp[b1][b2][s1][s2]) continue;
	  
	  REP(manji, MAX) {
	    int dokle = (s1 + s2 == 4) ? 15 : 25;
	    int veci = max(dokle, manji+2);

	    if (b1 + manji < MAX && b2 + veci < MAX) {
	      dp[b1+manji][b2+veci][s1][s2+1] = 1;
	      odakle[b1+manji][b2+veci][s1][s2+1] = make_tuple(b1, b2, s1, s2);
	    }

	    if (b1 + veci < MAX && b2 + manji < MAX) {
	      dp[b1+veci][b2+manji][s1+1][s2] = 1;
	      odakle[b1+veci][b2+manji][s1+1][s2] = make_tuple(b1, b2, s1, s2);
	    }
	  }	    
	}
      }
    }
  }

  int q;
  scanf("%d", &q);

  REP(iii, q) {
    int b1, b2;
    scanf("%d%d", &b1, &b2);

    int s1 = -1, s2 = -1, bst = -1000;

    REP(i, MAXS) REP(j, MAXS)
      if (max(i, j) == 3 && i-j > bst && dp[b1][b2][i][j])
	s1 = i, s2 = j, bst = i-j;

    if (bst == -1000) printf("Impossible\n");
    else {
      printf("%d:%d\n", s1, s2);
      vector <P> V;
      for (; s1 || s2; ) {
	auto tmp = odakle[b1][b2][s1][s2];
	V.push_back(P(b1 - get<0>(tmp), b2 - get<1>(tmp)));
	b1 = get<0>(tmp);	
	b2 = get<1>(tmp);
	s1 = get<2>(tmp);
	s2 = get<3>(tmp);
      }

      reverse(V.begin(), V.end());
      for (auto it : V)
	printf("%d:%d ", it.x, it.y);
      printf("\n");
    }
  }
  

  return 0;
}