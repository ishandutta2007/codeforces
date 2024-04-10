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
bool unable[10000];
PII judge(vector<int> a, vector<int> b){
  int bul=0,cow=0;
  REP(i,4)if(a[i]==b[i]) bul++;
  REP(i,4)REP(j,4)if(i!=j&&a[i]==b[j]) cow++;
  return PII(bul,cow);
}
vector<int> itov(int n){
  vector<int> res;
  REP(i,4){
    int tmp = n%10;
    n/=10;
    if(find(res.begin(),res.end(),tmp)!=res.end()) return vector<int>();
    res.push_back(tmp);
  }
  return res;
}

int main(void){
  memset(unable,0,sizeof(unable));
  int n;
  cin>>n;
  while(n--){
    int a,b,c;
    cin>>a>>b>>c;
    PII par = PII(b,c);
    vector<int> cas = itov(a);
    REP(i,10000){
      vector<int> test = itov(i);
      if(test==vector<int>()) continue;
      PII par2 = judge(cas,test);
      if(par!=par2) unable[i] = true;
    }
  }
  int count = 0;
  REP(i,10000){
    vector<int> test = itov(i);
    if(test==vector<int>()) continue;
    if(!unable[i]) count++;
  }
  if(count==0) cout<<"Incorrect data"<<endl;
  else if(count>1) cout<<"Need more data"<<endl;
  else {
    REP(i,10000){
      vector<int> test = itov(i);
      if(test==vector<int>()) continue;
      if(!unable[i]){
        if(i<1000) cout<<"0";
        cout<<i<<endl;
      }
    }
  }
  return 0;
}