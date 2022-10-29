#include <iostream>

using namespace std;

int main()
{
   long n,a[50][50]={0},i,j,s=0;
   cin>>n;
   for(i=0;i<n;++i)
   for(j=1;j<=n;++j)
     a[i][j-1]=n*i+j;
   for(i=0;i<n/2;i++,i++)
       {   
           if((n-2*i)%4==1) i++;
           swap(a[n-1-i][i],a[n-1-i][n-2-i]);
           swap(a[i][n-1-i],a[i][n-2-i]);
           swap(a[i][i],a[i+1][i]);
           swap(a[i+1][n-1-i],a[n-1-i][n-1-i]);
       }
   for(i=0;i<n;++i)
   {for(j=0;j<n;++j)
     cout<<a[i][j]<<" ";cout<<endl;}
      return 0;
}