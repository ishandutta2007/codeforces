#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  double s, av, a, b;
  scanf("%lf%lf", &s, &av);
  for(int i=1; i<n; i++)
  {
    scanf("%lf%lf", &a, &b);
    s += a;
    av += b;
  }
  printf("%lf", 5+av/n);
  return 0;
}