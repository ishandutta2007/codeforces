#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
   ll t;
   cin>>t;
   while(t--)
   {
      int k,n;
      string s;
   cin>>n>>k>>s;
   sort(s.begin(),s.end());
   if(s[0]!=s[k-1]||k==n){cout<<s[k-1]<<endl;continue;}
  int u=1;
  for(int i=1;i<n;i++)if(s[i]!=s[i-1])u++;
  if(u>2){for(int i=k-1;i<n;i++)cout<<s[i];cout<<endl;continue;}
  if(u==1){int v=(n+k-1)/k;for(int i=0;i<v;i++)cout<<s[0];cout<<endl;continue;}
  if(u==2)
  {
      if(s[k]==s[k-1]){for(int i=k-1;i<n;i++)cout<<s[i];cout<<endl;continue;}
      int v=(n-1)/k;
      cout<<s[0];
      for(int i=0;i<v;i++)cout<<s[k];
      cout<<endl;
  }

   }
   return 0;
}