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

const int INF = 45;
vector <long long> trzy[INF];

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    long long x;
    cin >> x;
    long long y = x;
    int k = 0;
    while(y % 3 == 0) {
      y /= 3;
      k++;
    }
    trzy[k].push_back(x);
  }
  for(int i=INF-1; i>=0; i--) {
    sort(trzy[i].begin(), trzy[i].end());
    for(auto t : trzy[i]) cout << t << " ";
  }
  return 0;
}