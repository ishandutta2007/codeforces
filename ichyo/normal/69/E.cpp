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
  vector<int> a(n);
  REP(i,n)cin>>a[i];
  map<int,int> table;
  set<int> once;
  REP(i,n){
    if(++table[a[i]] == 1) once.insert(a[i]);
    else once.erase(a[i]);

    if(i>=k){
      int c = --table[a[i-k]];
      if(c==1) once.insert(a[i-k]);
      else if(c==0) once.erase(a[i-k]);
    }

    if(i>=k-1){
      if(once.empty()) cout<<"Nothing"<<endl;
      else{
        set<int>::iterator ite = once.end();
        --ite;
        cout<<*ite<<endl;
      }
    }
  }
  return 0;
}