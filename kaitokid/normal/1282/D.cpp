#include <bits/stdc++.h>

using namespace std;
char ans[309];
int n,x,a,b;
int main()
{
    ios::sync_with_stdio(0);
    cout<<"a"<<endl;
    fflush(stdout);
    cin>>x;
    if(x==0)return 0;
    n=x+1;
    for(int i=0;i<x;i++)cout<<"b";
    cout<<endl;
    fflush(stdout);
    cin>>x;
    if(x==0)return 0;
    a=x;
    b=n-a;
    for(int i=0;i<n;i++)
    {for(int j=0;j<i;j++)cout<<ans[j];
        if(a==0){for(int j=i;j<n;j++)cout<<"b";cout<<endl;fflush(stdout);cin>>x;return 0;}
        if(b==0){for(int j=i;j<n;j++)cout<<"a";cout<<endl;fflush(stdout);cin>>x;return 0;}
  cout<<"a";
  for(int j=i+1;j<n;j++)cout<<"b";
  cout<<endl;
  fflush(stdout);
  cin>>x;
  if(x==0)return 0;
  if(x==a-1){ans[i]='a';a--;continue;}
  ans[i]='b';
  b--;

    }
}