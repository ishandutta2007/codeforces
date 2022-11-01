#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define bit first
#define str second

using namespace std;

struct container{
  map<char, string> all;
  bool change;

  container() : change(false){}

  bool changed(){bool tmp = change; change = false; return tmp;}

  void update(char bit, string str){
    if (!all.count(bit) ||
	all[bit].size() > str.size() ||
	(all[bit].size() == str.size() &&
	 all[bit] > str)){
      all[bit] = str;
      change = true;
    }
  }

  auto begin(){return all.begin();}
  auto end(){return all.end();}
};

int main(){
  ios_base::sync_with_stdio(false);

  container E, T, F;
  F.update(15, "x");
  F.update(51, "y");
  F.update(85, "z");

  while (E.changed() || T.changed() || F.changed()){
    { // E
      container tmp = E;
      for (auto A : E)
	for (auto B : T)
	  tmp.update(A.bit | B.bit, A.str + "|" + B.str);
      for (auto A : T)
	tmp.update(A.bit, A.str);
      E = tmp;
    }

    { // T
      container tmp = T;
      for (auto A : T)
	for (auto B : F)
	  tmp.update(A.bit & B.bit, A.str + "&" + B.str);
      for (auto A : F)
	tmp.update(A.bit, A.str);
      T = tmp;
    }

    { // F
      container tmp = F;
      for (auto A : F)
	tmp.update((char)~A.bit, "!" + A.str);
      for (auto A : E)
	tmp.update(A.bit, "(" + A.str + ")");
      F = tmp;
    }
  }

  int n;
  cin >> n;
  REP(blatruc,n){
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    int bit = 0;
    REP(i,8) if (str[i] == '1') bit |= (1<<i);
    cout << E.all[(char)bit] << endl;
  }

  return 0;
}