#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(void) {
  string pattern = "CODEFORCES";
  string str;
  cin >> str;
  if (str.size() < pattern.size()) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i <= pattern.size(); ++i) {
    if (str.substr(0, i) + str.substr(str.size() - pattern.size() + i) == pattern) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}