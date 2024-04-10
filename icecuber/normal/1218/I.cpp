#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[2000][2000];
int b[2000][2000];
int rod[2000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < n; j++) {
	int flip = s[j]-'0';
	a[i][j] ^= flip;
      }
    }
  }
  int onei = -1;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    rod[i] = s[i]-'0';
    if (rod[i]) onei = i;
  }

  vector<int> rows, cols;
  for (int flip : {0,1}) {
    copy_n((int*)a, 2000*2000, (int*)b);
    if (onei != -1) {
      if (flip) {
	rows.push_back(onei);
	for (int j = 0; j < n; j++)
	  b[onei][j] ^= rod[j];
      }
      for (int j = 0; j < n; j++) {
	if (b[onei][j]) {
	  cols.push_back(j);
	  for (int i = 0; i < n; i++)
	    b[i][j] ^= rod[i];
	}
      }
      for (int i = 0; i < n; i++) {
	int any = 0;
	for (int j = 0; j < n; j++)
	  any |= b[i][j];
	if (any) {
	  rows.push_back(i);
	  for (int j = 0; j < n; j++)
	    b[i][j] ^= rod[j];
	}
      }
    }

    int any = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	any |= b[i][j];
	//cout << b[i][j];
      }
      //cout << endl;
    }
    //cout << endl;
    if (any) continue;

    cout << rows.size()+cols.size() << '\n';
    for (int i : rows)
      cout << "row " << i << '\n';
    for (int i : cols)
      cout << "col " << i << '\n';
    return 0;
  }
  cout << -1 << endl;
}