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
struct tree{ 
  string name; 
  vector<tree> child; 
  int file;
  tree(string s){ name = s; file = 0;}
};
int count_fold(tree& fold){
  int res = fold.child.size();
  REP(i,fold.child.size()){
    res += count_fold(fold.child[i]);
  }
  return res;
}
int count_file(tree& fold){
  int res = fold.file;
  REP(i,fold.child.size()){
    res += count_file(fold.child[i]);
  }
  return res;
}
int main(void){
  vector<tree> root;
  REP(i,5){
    string s = "C";
    s[0] = s[0]+i;
    root.push_back(tree(s));
  }
  string line;
  while(cin>>line){
    int rootindex = line[0] -'C';
    tree* folder = &root[rootindex];
    for(int i=3; i<line.size();){
      int j=i;
      while(j<line.size()&&line[j]!='\\')j++;
      if(j==line.size()){
        folder->file++;
      }else{
        string newfold;
        for(int index = i; index<j; index++){
          newfold += line[index];
        }
        int k=0;
        while(k < folder->child.size()&&folder->child[k].name!=newfold) k++;
        if(k==folder->child.size()){
          folder->child.push_back(tree(newfold));
          folder = &folder->child[k];
        }else{
          folder = &folder->child[k];
        }
      }
      i = j+1;
    }
  }
  int a=0;
  int b=0;
  REP(i,5){
    REP(j,root[i].child.size()){
      a = max(a, count_fold(root[i].child[j]));
      b = max(b, count_file(root[i].child[j]));
    }
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}