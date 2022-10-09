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
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  vector <int> pre(256, -1);
  for(int i=0; i<n; i++) {
    cin >> a[i];
    int pos = a[i];
    for(int e=0; e<k; e++) {
      if(a[i]-e >= 0) {
        if(pre[a[i]-e] == -1) {
          pos = a[i]-e;
        } else if(a[i] - pre[a[i]-e] < k) {
          pos = pre[a[i]-e];
          break;
        }
      }
    }
    for(int e=pos; e<=a[i]; e++) {
      pre[e] = pos;
    }
    cout << pre[a[i]] << " ";
  }
  cout << "\n";
  return 0;
}