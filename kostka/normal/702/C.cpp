#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector <long long> b(n);
  for(int i=0; i<n; i++)
    cin >> b[i];
  vector <long long> a(m+2);
  a[0] = -2*1e12;
  a[m+1] = 2*1e12;
  for(int i=1; i<=m; i++)
    cin >> a[i];
  long long res = 0;
  for(int i=0; i<n; i++)
  {
    long long x = b[i];
    auto tmp = lower_bound(a.begin(), a.end(), x);
    long long wprawo = *tmp;
    tmp--;
    long long wlewo = *tmp;
    //cerr << wlewo << " " << wprawo << "\n";
    res = max(res, min((x-wlewo), (wprawo-x)));
  }
  cout << res << "\n";
}