#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200008];
int main()
{
ios::sync_with_stdio(0);
int t,n,x;
cin>>t;
while(t--)
{

   cin>>n;
   for(int i=0;i<n;i++)cin>>a[i];
   if(n==1){cout<<0<<endl;continue;}
   int u=n-2;
   while(u>-1&&a[u]>=a[u+1])u--;
   if(u<=0){cout<<0<<endl;continue;}
   u--;
   while(u>-1&&a[u]<=a[u+1])u--;
   cout<<u+1<<endl;

}
    return 0;
}