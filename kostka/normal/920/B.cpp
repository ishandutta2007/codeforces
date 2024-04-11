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

void test() {
  int n;
  cin >> n;
  vector <pii> X(n);
  vector <int> ans(n);
  for(int i=0; i<n; i++) {
    cin >> X[i].x >> X[i].y;
  }
  queue <int> Q;
  int wsk = 0;
  for(int t=1; t<=5000; t++) {
    while(wsk < SZ(X) and X[wsk].x == t) {
      Q.push(wsk++);
    }
    while(!Q.empty()) {
      int it = Q.front();
      Q.pop();
      if(X[it].y >= t) {
        ans[it] = t;
        break;
      }
    }
  }
  for(int i=0; i<n; i++) cout << ans[i] << " ";
  cout << "\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) test();
  return 0;
}