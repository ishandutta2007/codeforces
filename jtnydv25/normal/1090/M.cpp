#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

int main() {
  int n,k;
  S2(n,k);
  int p;
  int ans = 0;
  int cnt = 0;
  rep(i,0,n) {
    int x;
    S(x);
    if(i && p != x) {
      cnt++;
    } else {
      cnt = 1;
    }
    p = x;
    ans = max(ans, cnt);
  }
  P(ans);
  return 0;
}