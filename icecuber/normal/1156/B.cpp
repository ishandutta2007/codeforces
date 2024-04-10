#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string gen(int*count, int flip) {
  string r = "";
  for (int i = flip; i < 26; i += 2)
    for (int j = 0; j < count[i]; j++)
      r += i+'a';
  for (int i = !flip; i < 26; i += 2)
    for (int j = 0; j < count[i]; j++)
      r += i+'a';
  //cout << r << endl;
  return r;
}

int check(string s) {
  char last = ' ';
  for (char c : s) {
    if (abs(c-last) == 1) return 0;
    last = c;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int count[26] = {};
    for (char c : s) count[c-'a']++;
    string a = gen(count, 0), b = gen(count, 1);
    if (check(a)) cout << a << endl;
    else if (check(b)) cout << b << endl;
    else cout << "No answer" << endl;
  }
}