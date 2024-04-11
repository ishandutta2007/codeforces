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
  vector <int> A(n), P(n);
  multiset <int> MS;
  for(int i=0; i<n; i++) {
    cin >> A[i];
  }
  for(int i=0; i<n; i++) {
    int p;
    cin >> p;
    MS.insert(p);
  }
  for(int a=0; a<n; a++) {
    int curmask = 0;
    for(int i=30; i>=0; i--) {
      if((1<<i) & A[a]) {
        if(MS.lower_bound(curmask | (1<<i)) != MS.upper_bound(curmask | ((1<<(i+1))-1))) {
          curmask |= (1<<i);
        }
      } else {
        if(MS.lower_bound(curmask) == MS.lower_bound(curmask | (1<<i))) {
          curmask |= (1<<i);
        }
      }
    }
    cout << (A[a] ^ curmask) << " ";
    MS.erase(MS.find(curmask));
  }
  cout << "\n";
  return 0;
}