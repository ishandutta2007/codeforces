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

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n;
  cin>>n;
  vector<int> s(n);
  REP(i,n)cin>>s[i];
  int ans = 0;
  REP(i,n){
    int tmp = 1;
    bool right = true;
    bool left = true;
    FOR(j,1,n){
      if(i-j>=0&&left){
        if(s[i-j]<=s[i-j+1]){
          tmp++;
        }else{
          left = false;
        }
      }
      if(i+j<n&&right){
        if(s[i+j]<=s[i+j-1]){
          tmp++;
        }else{
          right = false;
        }
      }
    }
    ans = max(ans,tmp);
  }
  cout<<ans<<endl;


  return 0;
}