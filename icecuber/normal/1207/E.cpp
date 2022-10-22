#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << "? ";
  for (int i = 1; i <= 100; i++)
    cout << i << ' ';
  cout << endl;
  int a;
  cin >> a;
  cout << "? ";
  for (int i = 1; i <= 100; i++)
    cout << (i<<7) << ' ';
  cout << endl;
  int b;
  cin >> b;
  cout << "! " << ((a>>7)<<7)+(b&(1<<7)-1) << endl;
}