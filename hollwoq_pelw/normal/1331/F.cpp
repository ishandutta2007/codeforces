#include <bits/stdc++.h>

using namespace std;

vector<string> els = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (string& x : els) {
    if (x.size() == 2) {
      x[1] = (char) toupper(x[1]);
    }
  }
  string s;
  cin >> s;
  vector<bool> dp(s.size() + 1);
  dp[0] = true;
  for (int i = 0; i < (int) s.size(); i++) {
    if (dp[i]) {
      for (string w : els) {
        if (s.substr(i, w.size()) == w) {
          dp[i + (int) w.size()] = true;
        }
      }
    }
  }
  cout << (dp.back() ? "YES" : "NO") << '\n';
  return 0;
}