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
  string str;
  string word;
  cin>>n;
  cin.ignore();
  getline(cin,str);
  stringstream ss(str);
  int ans=1;
  int len=0;
  int s_size=0;
  while(ss>>word){
    if(s_size) s_size++;
    s_size += word.size();
    if(word[word.size()-1]=='.'||
        word[word.size()-1]=='?'||
        word[word.size()-1]=='!'){
      if(s_size>n){
        ans = -1;
        break;
      }else if(len==0){
        len = s_size;
        s_size = 0;
      }else if(len+s_size+1>n){
        len = s_size;
        s_size = 0;
        ans++;
      }else{
        len += s_size+1;
        s_size = 0;
      }
    }
  }
  if(ans==-1)cout<<"Impossible"<<endl;
  else cout<<ans<<endl;



  return 0;
}