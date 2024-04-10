#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,m,i,j,c=0,x1,y1,x2,y2;
   char a[501][501];
   cin>>n>>m;
   x1=n-1;
   x2=0;
   y1=m-1;
   y2=0;
   for(i=0;i<n;++i)
    cin>>a[i];
   for(i=0;i<n;++i)
   {
     for(j=0;j<m;++j)
     if(a[i][j]=='X')
     {if(i<x1)x1=i;
       if(i>x2) x2=i;
       if(j<y1) y1=j;
       if(j>y2) y2=j;
     }
   }
   //cout<<x1<<x2<<y1<<y2<<endl;
   for(i=x1;i<=x2;++i)
    for(j=y1;j<=y2;++j)
   if(a[i][j]!='X') {cout<<"NO";exit(0);}
    cout<<"YES";
    return 0;
}