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
  int n, w;
  cin >> n >> w;
  ll low_bound = 0, upp_bound = w;
  ll L = 0, R = w;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    low_bound += x;
    upp_bound += x;
    if(low_bound < 0) {
      L += 0 - low_bound;
      low_bound = 0;
    }
    if(upp_bound > w) {
      R -= upp_bound - w;
      upp_bound = w;
    }
  }
  cout << max(0LL, R-L+1) << "\n";
  return 0;
}