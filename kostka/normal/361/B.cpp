#include<cstdio>
#include<vector>

using namespace std;

// int gcd(int a, int b)
// {
//   return b==0 ? a : gcd(b, a%b);
// }

int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  if(k==n)
  {
    puts("-1");
    return 0;
  }
  if(k==n-1)
  {
    for(int i=1; i<=n; i++)
      printf("%d ", i);
    return 0;
  }
  vector <int> X;
  X.push_back(k+2);
  for(int i=1; i<=k; i++)
    X.push_back(i+1);
  for(int i=k+1; i<n-1; i++)
    X.push_back(i+2);
  X.push_back(1);
  for(int i=0; i<X.size(); i++)
    printf("%d ", X[i]);
//   int wyn = 0;
//   for(int i=0; i<n; i++)
//     if(gcd(X[i], i+1)>1)
//       wyn++;
//   if(wyn!=k)
//   {
//     printf("\n!");
//     printf("\n%d %d\n", wyn, k); 
//   }
//   else
//     printf("\n.\n");
  return 0;
}