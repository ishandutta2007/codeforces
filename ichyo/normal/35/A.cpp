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
#include <fstream>

using namespace std;
typedef long long LL;
static const double EPS = 1e-9;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  ifstream infile("input.txt");
  ofstream outfile("output.txt"); 
  int ball;
  infile>>ball;
  int s1,s2;
  for(int i=0; i<3; i++){
    infile>>s1>>s2;
    if(s1==ball){
      ball=s2;
    }else if(s2==ball){
      ball=s1;
    }
  }
  outfile<<ball<<endl;
  return 0;
}