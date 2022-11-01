#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pii pair < int, int >
#define pb push_back
#define x first
#define y second
#define ll long long

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

void imp(){cout << "Impossible\n"; exit(0);}

string s;

map < char, int > type =
  {
    {'<',  1},
    {'[',  1},
    {'{',  1},
    {'(',  1},
    {'>', -1},
    {']', -1},
    {'}', -1},
    {')', -1}
  };

map < char, char > flip =
  {
    {'>', '<'},
    {']', '['},
    {'}', '{'},
    {')', '('}
  };

int main(){

  cin >> s;
  int testcnt = 0;
  for (auto x : s){
    testcnt += type[x];
    if (testcnt < 0) imp();
  } if (testcnt) imp();

  stack < char > S;
  int r = 0;
  for (auto x : s){
    if (type[x] == 1) S.push(x);
    else {
      x = flip[x];
      if (x != S.top()) ++r;
      S.pop();
    }
  } cout << r << endl;
  
  return 0;
}