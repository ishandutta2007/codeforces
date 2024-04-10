#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
   int t;
   cin>>t;
   while(t--)
   {
       int n,x,a,b,u=0;
       cin>>n>>x;
       for(int i=0;i<n-1;i++)
       {
           cin>>a>>b;
           if(a==x||b==x)u++;
       }
       if(u<2){cout<<"Ayush\n";continue;}
       int d=n-2;
       if(d%2==0){cout<<"Ayush\n";continue;}
       cout<<"Ashish\n";
   }
    return 0;
}