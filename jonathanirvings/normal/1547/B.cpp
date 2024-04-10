#include <bits/stdc++.h>
using namespace std;

constexpr int kMaxLen = 26;
const string kYes = "YES";
const string kNo = "NO";

string get_string() {
  char buffer[kMaxLen + 1];
  scanf("%s", buffer);
  string res = buffer;
  return res;
}

bool all_char(string S) {
  sort(S.begin(), S.end());
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] - 'a' != i) {
      return false;
    }
  }
  return true;
}

bool sorted(string S) {
  string T = S;
  sort(T.begin(), T.end());
  return S == T;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    string S = get_string();
    if (all_char(S)) {
      string l = "", r = "";
      bool add_left = true;
      for (int i = 0; i < S.size(); ++i) {
        if (S[i] == 'a') {
          add_left = false;
        } else {
          if (add_left) {
            l += S[i];
          } else {
            r += S[i];
          }
        }
      }
      reverse(l.begin(), l.end());
      puts(sorted(l) && sorted(r) ? kYes.c_str() : kNo.c_str());
    } else {
      puts(kNo.c_str());
    }
  }
}