#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef complex<double> P;
static const double EPS = 1e-8;
static const int INF = (int)1e8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FIND(m,w) ((m).find(w)!=(m).end())

int main(void){
  int m;
  cin>>m;
  int d[5][5]={};
  REP(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    d[a][b] = d[b][a] = 1;
  }
  bool ans = false;
  REP(i,5)FOR(j,i+1,5)FOR(k,j+1,5){
    int sum = d[i][j]+d[j][k]+d[k][i];
    if(sum==0||sum==3){
      ans = true;
    }
      
  }
  if(ans)cout<<"WIN"<<endl;
  else cout<<"FAIL"<<endl;
  return 0;
}