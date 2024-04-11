//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

map <char, int> known;

#define UNKNOWN 0
#define MAYBE 1
#define XXX 2
#define NOT -1

int unique() {
  int ile = 0;
  for(char x='a'; x<='z'; x++) {
    if(known[x] == MAYBE) ile++;
  }
  if(ile == 1) return true;
  ile = 0;
  for(char x='a'; x<='z'; x++) {
    if(known[x] == NOT) ile++;
  }
  if(ile == 25) return true;
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <pair <string, string> > W;
  for(int i=0; i<n; i++) {
    string x, y;
    cin >> x >> y;
    sort(y.begin(), y.end());
    W.emplace_back(x, y);
  }
  bool en = false;
  int res = 0;
  for(int i=0; i<n-1; i++) {
    if(en) {
      if(W[i].first == "?" or W[i].first == "!") res++;
      continue;
    }
    if(W[i].first == "!") {
      map <char, bool> exists;
      for(auto w : W[i].second) {
        exists[w] = true;
      }
      for(char x='a'; x<='z'; x++) {
        if(!exists[x]) known[x] = NOT;
        else if(known[x] == UNKNOWN) known[x] = MAYBE;
      }
    } else {
      for(auto w : W[i].second) {
        known[w] = NOT;
      }
    }
    if(unique()) {
      en = true;
    }
  }
  cout << res << "\n";
  return 0;
}