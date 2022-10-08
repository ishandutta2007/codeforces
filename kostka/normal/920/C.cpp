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
  vector <int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  string x;
  cin >> x;
  for(int i=0; i+1<n; i++) {
    if(x[i] == '1') {
      int start = i;
      int end = i+1;
      while(i+1<n and x[i] == '1') {
        i++;
        end++;
      }
      sort(a.begin()+start, a.begin()+end);
    }
  }
  for(int i=0; i<n; i++) {
    if(i+1 != a[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}