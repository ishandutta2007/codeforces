#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int main(){
  int N;
  cin>>N;
  vector<int> a(N + 1);
  REP(i, N) cin>>a[i + 1];
  if(N % 2 == 0 || N == 1){
    cout<<-1<<endl;
  }else{
    /*
    int ans = 0;
    int B = (N - 1)/2;
    for(int x = 1; x <= B; x++){
      while(true){
        if(a[x] <= 0 && (a[2 * x] <= 0 || 2 * x <= B) && (a[2 * x + 1] <= 0 || 2 * x + 1 <= B)){
          break;
        }
        a[x]--; a[2 * x]--; a[2 * x + 1]--;
        ans ++;
      }
    }
    cout<<ans<<endl;
    */
    int ans = 0;
    for(int x = N; x >= 1; x--){
      if(x % 2 == 1 && a[x] > 0){
        ans += a[x];
        a[x - 1] -= a[x];
        a[x/2] -= a[x];
      }else if(x % 2 == 0 && a[x] > 0){
        ans += a[x];
        a[x/2] -= a[x];
      }
    }
    cout<<ans<<endl;
  }

  return 0;
}