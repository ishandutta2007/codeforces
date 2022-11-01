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
  string line;
  int a[3];
  bool wrong = false;
  REP(i,3)a[i]=-1;
  while(cin>>line){
    int k1=line[0]-'A';
    int k2=line[2]-'A';
    if(line[1]=='<')swap(k1,k2);
    if(a[k1]!=-1){
      if(a[k2]!=-1){
        if(a[k1]<a[k2]) wrong = true;
        else if(a[k1]==a[k2]){
          if(a[k1]==10) a[k1]=11;
          else a[k2] = 8;
        }
      }else{
        a[k2] = a[k1] -1;
      }
    }else{
      if(a[k2]!=-1){
        a[k1] = a[k2] + 1;
      }else{
        a[k1] = 10;
        a[k2] = 9;
      }
    }
  }
  REP(i,3) if(a[i]==-1) wrong=true;
  if(a[0]==a[1]||a[1]==a[2]||a[2]==a[0]) wrong = true;
  if(wrong){
    cout<<"Impossible"<<endl;
  }else{
    PII data[3] = {PII(a[0],0),PII(a[1],1),PII(a[2],2)};
    sort(data,data+3);
    printf("%c%c%c\n",'A'+data[0].second,'A'+data[1].second,'A'+data[2].second);
  }
  return 0;
}