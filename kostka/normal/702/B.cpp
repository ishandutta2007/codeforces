#include "iostream"
#include "unordered_map"

using namespace std;

unordered_map <int, int> X;

int main()
{
  int n;
  cin >> n;
  long long res = 0;
  for(int i=0; i<n; i++)
  {
    int x;
    cin >> x;
    for(int e=1; e<=30; e++)
    {
      if(x <= (1<<e))
        res += X[(1<<e) - x];
    }
    X[x] += 1;
  }
  cout << res << "\n";
}