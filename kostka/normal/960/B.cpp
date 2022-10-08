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
  int n, a, b;
  cin >> n >> a >> b;
  vector <int> A(n), B(n);
  for(int i=0; i<n; i++) {
    cin >> A[i];
  }
  for(int i=0; i<n; i++) {
    cin >> B[i];
  }
  priority_queue <int> Q;
  for(int i=0; i<n; i++) {
    Q.push(abs(B[i]-A[i]));
  }
  int ct = a+b;
  while(ct--) {
    int q = Q.top();
    Q.pop();
    if(q == 0) Q.push(1);
    else Q.push(q-1);
  }
  ll ret = 0;
  while(!Q.empty()) {
    int q = Q.top();
    Q.pop();
    ret += 1LL*q*q;
  }
  cout << ret << "\n";
  return 0;
}