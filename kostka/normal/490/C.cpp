#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1000007;
bool czy1[MAXN], czy2[MAXN];

int main()
{
  string x;
  cin >> x;
  int n = (int)x.size();
  int a, b;
  cin >> a >> b;
  long long t = 0;
  for(int i=0; i<n; i++)
  {
    t = (t*10)%a;
    t = (t+(x[i]-'0'))%a;
    //cerr << t << " ";
    if(t==0)
      czy1[i] = true;
  }
  cerr << "\n";
  long long s = 0;
  bool ttt = false;
  long long mn = 1;
  for(int i=n-1; i>=0; i--)
  {
    s = (s+(x[i]-'0')*mn);
    mn = (mn*10)%b;
    //cerr << s << " ";
    if(ttt || (x[i] != '0'))
    {
      ttt = true;
      s = s % b;
      if((s==0) && (x[i]!='0'))
        czy2[i] = true;
    }
  }
  cerr << "\n";
  for(int i=0; i<n-1; i++)
    if(czy1[i] && czy2[i+1])
    {
      puts("YES");
      for(int k=0; k<=i; k++)
        cout << x[k];
      cout << "\n";
      for(int k=i+1; k<n; k++)
        cout << x[k];
      return 0;
    }
  puts("NO");
  return 0;
}