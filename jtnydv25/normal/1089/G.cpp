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

int A[11];

int main() {
  int t;
  S(t);
  while(t--) {
    int k;
    S(k);
    int cnt = 0;
    rep(i,0,7) {
      S(A[i]);
      cnt += A[i];
    }
    int ans = 0;
    if(k % cnt) {
      ans = (k / cnt) * 7;
      k %= cnt;
    } else {
      ans = (k / cnt) * 7;
      ans -= 7;
      k = cnt;
    }

    if(k) {
      int mn = 7;
      rep(i,0,7) if(A[i]) {
        int sm = 0;
        rep(j,0,7) {
          sm += A[(i + j) % 7];
          if(sm == k) {
            mn = min(mn, j + 1);
            break;
          }
        }
      }
      ans = ans + mn;
    }
    P(ans);
  }
  return 0;
}