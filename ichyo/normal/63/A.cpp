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
  vector< pair<string,string> > data;
  REP(i,n){
    string name,cha;
    cin>>name>>cha;
    data.push_back( pair<string,string>(name,cha));
  }
  REP(i,n){
    if(data[i].second=="rat") cout<<data[i].first<<endl;
  }
  REP(i,n){
    if(data[i].second=="woman"||data[i].second=="child") cout<<data[i].first<<endl;
  }
  REP(i,n){
    if(data[i].second=="man") cout<<data[i].first<<endl;
  }
  REP(i,n){
    if(data[i].second=="captain") cout<<data[i].first<<endl;
  }

  return 0;
}