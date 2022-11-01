#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n;
  cin>>n;
  string sset[11] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA"
    , "VODKA", "WHISKEY", "WINE"};
  int ans=0;
  REP(i,n){
    string s;
    cin>>s;
    int age = atoi(s.c_str());
    stringstream ss;
    ss<<age;
    string agestr;
    ss>>agestr;
    if(agestr==s){
      if(age<18) ans++;
    }else{
      REP(j,11){
        if(s==sset[j]) ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}