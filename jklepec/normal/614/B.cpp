#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

typedef pair<int, int> point;

string samp = "1";
string kolko;

int main() {
   int n; cin >> n;
   if(n == 1) {
      string s;
      cin >> s;
      cout << s;
      goto van;
   }
   for(int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      if(s.size() == 1 and s == "0") {
         cout << 0;
         goto van;
      }
      bool is = false;
      for(int j = 1; j < s.size(); ++j)
         if(s[j] != '0')
            is = true;
      if(is or s[0] != '1')
         samp = s;
      else
         kolko += s.substr(1, s.size() - 1);
   }
   cout << samp;
   cout << kolko;
   van:;
   return 0;
}