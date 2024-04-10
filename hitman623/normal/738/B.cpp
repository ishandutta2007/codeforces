#include <iostream>

using namespace std;
 int n,m,a[1001][1001]={0},i,j,c=0,s;
int main()
{

     cin>>n>>m;
     for(i=0;i<n;++i)
        for(j=0;j<m;j++)
        {cin>>a[i][j];a[i][m]+=a[i][j];a[n][j]+=a[i][j];}
     for(i=0;i<n;i++)
     {   s=0;
         for(j=0;j<m;++j)
         {
             if(a[i][j]==0)
             {
                 if(s>0) c++;
                 if(a[i][m]-s>0) c++;
             }
             else s++;
         }
     }
     for(i=0;i<m;i++)
     {   s=0;
         for(j=0;j<n;++j)
         {
             if(a[j][i]==0)
             {
                 if(s>0) c++;
                 if(a[n][i]-s>0) c++;
             }
             else s++;
         }
     }
     cout<<c;
    return 0;
}