#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main(){

  REP(i,10){
    cout << i << endl;
    string s;
    while (s == "") getline(cin, s);
    if (s == "no") continue;
    if (s == "cool"){cout << "normal" << endl; return 0;}
    if (s == "not bad"){cout << "normal" << endl; return 0;}
    if (s == "great!"){cout << "normal" << endl; return 0;}
    if (s == "great"){cout << "normal" << endl; return 0;}
    if (s == "don't think so"){cout << "normal" << endl; return 0;}
    if (s == "don't touch me!"){cout << "normal" << endl; return 0;}
    if (s == "don't touch me"){cout << "normal" << endl; return 0;}
    if (s == "don't touch me"){cout << "normal" << endl; return 0;}
    cout << "grumpy" << endl;
    return 0;
  }

  assert(false);

  return 0;
}