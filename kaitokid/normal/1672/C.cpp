#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009];
int main()
{
int t;
cin>>t;
while(t--)
{
 int n;
 cin>>n;
 for(int i=0;i<n;i++)cin>>a[i];
 int mx=-1,mn=-1;
 for(int i=1;i<n;i++)
 {
     if(a[i]==a[i-1]){mx=i;if(mn==-1)mn=i;}
 }
 if(mx==mn){cout<<0<<endl;continue;}
 int u=mx-mn;
 if(u==1)u++;
 cout<<u-1<<endl;

}

return 0;
}