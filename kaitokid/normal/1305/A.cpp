#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200],b[200];
int n,t;
int main()
{ios::sync_with_stdio(0);
 cin>>t;
 while(t--)
 {
     cin>>n;
     for(int i=0;i<n;i++)cin>>a[i];
     for(int i=0;i<n;i++)cin>>b[i];
     sort(a,a+n);
     sort(b,b+n);
     for(int i=0;i<n;i++)cout<<a[i]<<" ";
     cout<<endl;
     for(int i=0;i<n;i++)cout<<b[i]<<" ";
     cout<<endl;
 }


    return 0;
}