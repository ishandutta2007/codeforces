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

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
typedef pair<int,int> P;

int main(){
  int N;
  while(cin>>N){
    vector<P> points(N);
    REP(i,N){
      cin>>points[i].first>>points[i].second;
    }
    int ans = 0;
    sort(points.begin(), points.end());
    FOR(i,0,N)FOR(j,i+1,N){
      P p1 = points[i];
      P p2 = points[j];
      if(abs(p1.first + p2.first) % 2 == 0 && abs(p1.second + p2.second) % 2 == 0){
        if(binary_search(points.begin(), points.end(), P((p1.first+p2.first)/2, (p1.second+p2.second)/2))){
          ans ++;
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}