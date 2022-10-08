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

string x, y, ry;

long long go(int i, bool cokolwiek, multiset <int> M, string res = "") {
  if(i == -1) {
    //cout << res << "\n";
    if(stoll(res) <= stoll(y)) return stoll(res);
    return 0;
  }
  //cerr << "R" << res << "\n";
  int limit = ry[i]-'0';
  if(cokolwiek) limit += 10;
  //cerr << "L" << limit << "\n";
  auto it = M.upper_bound(limit);
  if(it != M.begin()) it--;
  ll ret = 0;
  //if((*it) < limit) {
   // M.erase(it);
   // res += char((*it)+'0');
   // ret = max(ret, go(i-1, true, M, res));
  // } else if((*it) == limit) {
    int w = (*it);
    M.erase(it);
    ret = max(ret, go(i-1, cokolwiek, M, res + char(w+'0')));
    M.insert(w);
    auto jt = M.lower_bound(limit);
    if(jt != M.begin()) jt--;
    //if(jt != M.begin()) {
      M.erase(jt);
      ret = max(ret, go(i-1, true, M, res + char((*jt)+'0')));
    //}
  // }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> x >> y;
  multiset <int> M;
  for(auto c : x) {
    M.insert(c-'0');
  }
  ry = y;
  reverse(ry.begin(), ry.end());
  cout << go((int)x.size()-1, (y.size() > x.size()), M) << "\n";
  return 0;
}