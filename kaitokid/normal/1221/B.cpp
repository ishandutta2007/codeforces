#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int q,n,a[60];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)for(int j=0;j<n;j++)if(j%2==0)cout<<"W";else cout<<"B";
        if(i%2==1)for(int j=0;j<n;j++)if(j%2==1)cout<<"W";else cout<<"B";
   cout<<endl;
    }
  return 0;
}