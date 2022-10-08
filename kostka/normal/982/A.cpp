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
  string x;
  cin >> x;
  x = 'a' + x + 'b';
  for(int i=1; i<=n; i++) {
    if(x[i] == '0' and x[i-1] != '1' and x[i+1] != '1') {
      puts("No");
      return 0;
    }
    if(x[i] == '1' and (x[i-1] == '1' or x[i+1] == '1')) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}