#include "iostream"
#include "algorithm"

using namespace std;

const int MAXN = 100007;
int a[MAXN];

int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  int res = 1;
  for(int i=0; i<n; i++)
  {
    int ile = 1;
    while(i+1 < n and a[i] < a[i+1])
    {
      ile++;
      i++;
    }
    res = max(res, ile);
  }
  cout << res << "\n";
}