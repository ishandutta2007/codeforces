#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll k;
  cin >> k;
  ll n = k/7e5+3;
  if (n%2==0) n++;
  cout << n << endl;
  for (int i = 0; i < n-2; i++)
    cout << -(i%2) << ' ';
  ll c = (n-2)/2;
  ll b = (k+c)%(n-1)-(n-1);
  ll a = (k+c-b)/(n-1)*n-k;
  cout << b << ' ' << a << endl;
  //cerr << (a+b-c)*n-a << endl;
}