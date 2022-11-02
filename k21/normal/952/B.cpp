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

int main() {
  set<string> grumpy, nonGrumpy;
  nonGrumpy.insert("don't think so");
  nonGrumpy.insert("not bad");
  nonGrumpy.insert("cool");
  nonGrumpy.insert("don't touch me!");
  nonGrumpy.insert("great!");
  grumpy.insert("are you serious?");
  grumpy.insert("terrible");
  grumpy.insert("worse");
  grumpy.insert("go die in a hole");
  grumpy.insert("no way");
  grumpy.insert("don't even");
  for (int i = 9; i >= 0; --i) {
    printf("%d\n", i);
    fflush(stdout);
    string answer;
    getline(cin, answer);
    if (grumpy.count(answer)) {
      printf("grumpy\n");
      break;
    } else if (nonGrumpy.count(answer)) {
      printf("normal\n");
      break;
    }
  }
  printf("grumpy\n");
  return 0;
}