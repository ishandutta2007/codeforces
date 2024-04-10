#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,x,a,b,y;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
  if(x<=3&&y>3){cout<<"NO\n";continue;}
  if(x==1&&y>1){cout<<"NO\n";continue;}
  cout<<"YES\n";
    }
    return 0;
}