#include<bits/stdc++.h>
using namespace std;

const int MAXX=1e5;
int t[MAXX+100],n,ans;

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    {
      int tmp;
      cin>>tmp;
      t[tmp]++;
    }
  ans=1;
  for(int i=1;i<=MAXX;i++)
    if(t[i]>0)
      if(t[i]%2) ans=0;
  if(ans==0) cout<<"Conan\n";
  else cout<<"Agasa\n";
}