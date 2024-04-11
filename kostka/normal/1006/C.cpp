//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vi a(n+2);
  for(int i=1; i<=n; i++) cin >> a[i];
  vector<ll> left(n+2), right(n+2);
  for(int i=1; i<=n; i++) left[i] += left[i-1] + a[i];
  for(int i=n; i>=1; i--) right[i] += right[i+1] + a[i];
  set <ll> S;
  ll ret = 0;
  for(int i=n; i>=0; i--) {
    S.insert(right[i+1]);
    if(S.find(left[i]) != S.end()) {
      ret = max(ret, left[i]);
    }
  }
  cout << ret << "\n";
  return 0;
}