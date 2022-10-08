#include "bits/stdc++.h"

using namespace std;

vector <pair <long long, long long>> E;

int main()
{
  long long n, r, avg;
  cin >> n >> r >> avg;
  long long wyn = avg*n;
  for(int i=0; i<n; i++)
  {
     long long a, b;
     cin >> a >> b;
     E.push_back({b,a});
     wyn -= a;
  }
  sort(E.begin(), E.end());
  wyn = max(wyn, 0LL);
  long long ile = 0;
  for(auto ele : E)
  {
    long long b = ele.first, a = ele.second;
    long long moge = min(wyn, r-a);
    //cerr << wyn << " " << ile << "\n";
    wyn -= moge;
    ile += 1LL*moge*b;
  }
  cout << ile << "\n";
}