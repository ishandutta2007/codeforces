#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string expr[200];
int dp[200][2]; // +-*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  cin.ignore();
  map<string,int> id;
  for (int i = 0; i <= n; i++) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string tmp;
    if (i != n) {
      ss >> tmp;
      if (tmp.size() == 1) ss >> tmp;
      string name;
      ss >> name;
      id[name] = i;
    }
    while (ss >> tmp) expr[i] += tmp;
  }
  //for (int i = 0; i <= n; i++)
  //  cout << expr[i] << endl;
  int op_id[256] = {};
  op_id['+'] = 1;
  op_id['-'] = 2;
  op_id['*'] = 3;
  op_id['/'] = 4;
  dp[n][0] = dp[n][1] = 1;
  for (int i = n; i >= 0; i--) {
    if (!dp[i][0] && !dp[i][1]) continue;
    int paras = 0;
    for (char c : expr[i]) {
      paras += (c == '(')-(c == ')');
      if (paras == 0) {
	//if (c == '+' || c == '-' || c == '*' || c == '/')
	//  cout << c << endl;
	int ok = 1;
	if ((dp[i][0]>>op_id['/']&1) &&
	    (c == '+' || c == '-' || c == '*' || c == '/')) ok = 0;
	if (((dp[i][0]>>op_id['*']&1) || (dp[i][0]>>op_id['-']&1) ||
	     (dp[i][1]>>op_id['*']&1) || (dp[i][1]>>op_id['/']&1)) &&
	    (c == '+' || c == '-')) ok = 0;
	if (!ok) {
	  cout << "Suspicious" << endl;
	  return 0;
	}
      }
    }

    int alpha_start = 0, last_was_alpha = 0;
    for (int j = 0; j <= expr[i].size(); j++) {
      int alpha = j < expr[i].size() ? isalpha(expr[i][j]) : 0;
      if (alpha && !last_was_alpha) {
	alpha_start = j;
      } else if (!alpha && last_was_alpha) {
	string s = expr[i].substr(alpha_start, j-alpha_start);
	if (id.count(s)) {
	  if (alpha_start == 0)
	    dp[id[s]][0] |= dp[i][0];
	  else
	    dp[id[s]][0] |= 1<<op_id[expr[i][alpha_start-1]];
	  if (j == expr[i].size())
	    dp[id[s]][1] |= dp[i][1];
	  else
	    dp[id[s]][1] |= 1<<op_id[expr[i][j]];
	}
      }
      last_was_alpha = alpha;
    }
  }
  cout << "OK" << endl;
}