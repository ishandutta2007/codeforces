#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

int i, nr;
string s, f;
vector<string> v1, v2;
map<string, string> M;

void toNextCite(string &s, int &poz) {
  while (poz < s.size() && s[poz] != '\\') ++poz;
  ++poz;
}

string getNextCite(string &s, int &poz) {
  poz += 5;
  string ans;
  while(poz < s.size() && s[poz] != '}') ans += s[poz++];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  while(getline(cin, s)) {
    if(!s.size()) continue;
    if(s.substr(0, 6) == "\\begin") break;
    for(i = 0, toNextCite(s, i); i < s.size(); toNextCite(s, i)) {
      string aux = getNextCite(s, i);
      v1.push_back(aux);
    }
  }

  f = s;
  while(getline(cin, s)) {
    if(!s.size()) continue;
    if(s.substr(0, 4) == "\\end") break;

    string aux;
    for(i = 0; s[i] != '{'; ++i);
    for(++i; s[i] != '}'; ++i) aux += s[i];
    M[aux] = s.substr(i + 1);
    v2.push_back(aux);
  }

  if(v1 == v2) return cout << "Correct\n", 0;

  cout << "Incorrect\n";
  cout << f << '\n';
  for(auto it : v1) cout << "\\bibitem{" << it << '}' << M[it] << '\n';
  cout << s << '\n';

  return 0;
}