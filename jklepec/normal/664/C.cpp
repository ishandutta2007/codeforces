#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define _ << " " <<

typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e5 + 5;

map<char, char> nxt = {{'0', '1'}, {'1', '2'}, {'2', '3'}, {'3', '4'}, {'4', '5'}, {'5', '6'}, {'6', '7'}, {'7', '8'}, {'8', '9'}, {'9', '0'}};

string dodaj(string &s) {
   string nw = "";
   bool dalje = true;

   int n = s.size();

   rep(j, n) {
      if(dalje) {
         nw = nxt[s[n - 1 - j]] + nw;
      }
      else {
         nw = s[n - 1 - j] + nw;
      }
      dalje = false;
      if(nw[0] == '0')
         dalje = true;
   }
   if(dalje)
      return "1" + nw;
   return nw;
}

void query(string s) {
   string m = "1988";
   vector<string> rijesi;

   int n = s.size();

   rep(j, n) {
      rijesi.push_back(s.substr(n - 1 - j, j + 1));
   }

   rep(i, n) {
      string nw = "";
      if(rijesi[i].size() > m.size()) {
         m = rijesi[i];
      }
      else {
         string fr = m.substr(0, m.size() - rijesi[i].size());
         string bk = m.substr(m.size() - rijesi[i].size(), rijesi[i].size());
         if(bk >= rijesi[i])
            m = dodaj(fr) + rijesi[i];
         else
            m = fr + rijesi[i];
      }
      if(m[0] == '0')
         m = "1" + m;
   }

   cout << m << '\n';
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int n; cin >> n;

   rep(i, n) {
      string s; cin >> s;
      query(s.substr(4, s.size() - 4));
   }
}