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
  vi a(2*n);
  for(int i=0; i<2*n; i++) cin >> a[i];
  int ret = 0;
  for(int i=0; i<2*n; i++) {
    for(int j=i+1; j<2*n; j++) {
      if(a[i] == a[j]) {
        for(int k=j; k>i+1; k--) {
          ret++;
          swap(a[k], a[k-1]);
        }
      }
    }
    i++;
  }
  for(int i=0; i<2*n; i+=2) {
    assert(a[i] == a[i+1]);
  }
  cout << ret << "\n";
  return 0;
}