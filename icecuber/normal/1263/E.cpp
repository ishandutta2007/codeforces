#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Side {
  vector<int> sum, mi, ma;
  Side() {
    sum = mi = ma = {0,0};
  }
  void push(int v) {
    sum.push_back(sum.back()+v);
    mi.push_back(min(mi.back(), sum.back()));
    ma.push_back(max(ma.back(), sum.back()));
  }
  int pop() {
    int ret = sum.back()-sum.end()[-2];
    if (sum.size() > 2) {
      sum.pop_back();
      mi.pop_back();
      ma.pop_back();
    }
    return -ret;
  }
};

int main() {
  int n;
  cin >> n;
  string input;
  cin >> input;
  Side left, right;
  int pos = 0;
  for (char c : input) {
    if (c == 'R') {
      pos++;
      left.push(right.pop());
    } else if (c == 'L') {
      if (pos > 0) {
	pos--;
	right.push(left.pop());
      }
    } else if (c == '(') {
      right.pop();
      right.push(-1);
    } else if (c == ')') {
      right.pop();
      right.push(1);
    } else {
      right.pop();
      right.push(0);
    }
    if (left.sum.back() == right.sum.back() && left.mi.back() >= 0 && right.mi.back() >= 0) {
      cout << max(left.ma.back(), right.ma.back()) << ' ';
    } else {
      cout << -1 << ' ';
    }
  }
  cout << endl;
}