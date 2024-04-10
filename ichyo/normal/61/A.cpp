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
  string s1,s2;
  cin>>s1>>s2;
  string ans;
  REP(i,s1.size()){
    if(s1[i]=='1'&&s2[i]=='0'){
      ans += '1';
    }else if(s1[i]=='0'&&s2[i]=='1'){
      ans += '1';
    }else{
      ans += '0';
    }
  }
  cout<<ans<<endl;
  return 0;
}