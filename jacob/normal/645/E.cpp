//============================================================================
// Name        : E.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = 1000 * 1000 * 1000 + 7;

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int m = (int)s.size();
	vector<int> lastPos(k, -1);
	vector<ll> resSum(1, 1LL);
	vector<ll> val(1, 1LL);
	auto addChar = [&](char ch) {
	  resSum.push_back(resSum.back() * 2);
	  if (lastPos[ch] != -1)
	    resSum.back() += MOD - resSum[lastPos[ch]];
	  resSum.back() %= MOD;
	  lastPos[ch] = int(resSum.size()) - 2;
	  //cerr << resSum.back() << endl;
	};
	for (int i = 0; i < m; ++i) {
	  addChar(s[i] - 'a');
	}
	for (int i = 0; i < n; ++i) {
	  int t = (min_element(lastPos.begin(), lastPos.end()) - lastPos.begin());
	  addChar(char(t));
	}
	cout << resSum.back() << endl;
	return 0;
}