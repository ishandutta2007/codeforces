#include <iostream>
#include <algorithm>

using namespace std;

int r[1000];
int main() {
  string s;
  cin >> s;
  int n = s.size();
  s += 'b';
  int rise = 0;
  for (int i = 0; i < n; i++) {
    if (s[i+1] == 'a') {
      //if (rise) reverse(&s[0], &s[i+1]);
      cout << rise << ' ';
      rise = 0;
    } else {
      //if (!rise) reverse(&s[0], &s[i+1]);
      cout << !rise << ' ';
      rise = 1;
    }
  }
  cout << endl;
  //cout << s << endl;
}