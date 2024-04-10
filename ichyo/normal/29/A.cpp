#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long LL;
static const double EPS = 1e-9;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n) 

int main(void){
  int n;
  vector<int> x;
  vector<int> d;
  cin>>n;
  REP(i,n){
    int tmp;
    cin>>tmp; x.push_back(tmp);
    cin>>tmp; d.push_back(tmp);
  }
  bool ans = false;
  REP(i,n){
    int y = x[i] + d[i];
    if(find(x.begin(),x.end(),y)!=x.end()){
      int j = distance(x.begin(),find(x.begin(),x.end(),y));
      if(x[i]==(x[j] + d[j])){
        ans = true;
        break;
      }
    }
  }
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}