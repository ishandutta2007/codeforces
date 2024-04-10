#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long LL;
static const double EPS = 1e-9;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  set<int> num;
  int tmp;
  char c;
  cin>>tmp;
  num.insert(tmp);
  while(cin>>c){
    cin>>tmp;
    num.insert(tmp);
  }
  vector<int> page;
  set<int>::iterator it = num.begin();
  while(it!=num.end()){
    tmp = *it;
    page.push_back(tmp);
    ++it;
  }
  int i=0;
  while(i<page.size()){
    if(i==page.size()-1){
      printf("%d\n",page[i]);
      break;
    }else if(page[i+1]-page[i]==1){
      int begin = i;
      while(page[i+1]-page[i]==1&&i!=page.size()-1) i++;
      if(i==page.size()-1){
        printf("%d-%d\n",page[begin],page[i++]);
        break;
      }else{
        printf("%d-%d,",page[begin],page[i++]);
      }
    }else{
      printf("%d,",page[i++]);
    }
  }
  return 0;
}