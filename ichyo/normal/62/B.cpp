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
  int n,k;
  cin>>n>>k;
  string enter;
  cin>>enter;
  vector<int> key[26];
  REP(i,enter.size()){
    key[enter[i]-'a'].push_back(i);
  }
  while(n--){
    LL ans = 0;
    string potent;
    cin>>potent;
    REP(i,potent.size()){
      int c = potent[i] - 'a';
      if(key[c].size()==0) ans+=(LL)potent.size();
      else{
        vector<int>::iterator it = upper_bound(key[c].begin(),key[c].end(),i);
        if(it==key[c].end()) it--;
        LL plus = abs(*it-i);
        if(it!=key[c].begin())it--;
        plus = min(plus, (LL)abs(*it-i));
        ans += plus;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}