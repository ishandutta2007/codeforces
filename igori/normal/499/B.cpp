#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define then ;
#define cin(n); int n; cin>>n;
#define stop return 0;
#define make(n) for(int i=0; i<n; i++)
//IgorI
//It is true or false
//Is it true or false?

//Codeforces 
//Problem 499B


int main()
{
    /*  int n,k;
    cin>>n>>k;
    int a[200000][2][2]={0};
 
    for(int i=0; i<n; i++)
       cin>>a[i][0][0];
    int m=0;
    int must=n;
    for(int i=0; i<n; i++)
       {cin>>a[i][1][0]; 
         if(a[i][0][0]>a[i][1][0])
           { a[i][0][1]=1; a[i][1][1]=a[i][0][0]-a[i][1][0]; must--;}
            
       }
    for(int i=0; i<n; i++)
    {
         for(int j=0; j<i; j++)
         {
              if(a[i][1][1]<a[j][1][1])
              {
                   int m=a[i][0][0];
                   a[i][0][0]=a[j][0][0];
                   a[j][0][0]=m;
                   
                   m=a[i][1][0];
                   a[i][1][0]=a[j][1][0];
                   a[j][1][0]=m;
                   
                   m=a[i][0][1];
                   a[i][0][1]=a[j][0][1];
                   a[j][0][1]=m;
                   
                   m=a[i][1][1];
                   a[i][1][1]=a[j][1][1];
                   a[j][1][1]=m;
              }
         }
    }
  /* for(int i=0; i<n; i++)
    {
         cout<<a[i][0][0]<<" "<<a[i][1][0]<<" "<<a[i][0][1]<<" "<<a[i][1][1]<<endl;
    } 
    long long ans=0;
    for(int i=0; i<max(k,must); i++)
    {
         ans+=a[i][0][0];
        
    }
    for(int i=max(k,must); i<n; i++)
    {
         ans+=a[i][1][0];
         
    }
    cout<<ans;*/
    
    int n,m;
    cin>>m>>n;
    string a[4000][2],s;
    make(n)
    {
         cin>>a[i][0]>>a[i][1];
    }
    make(m)
    {
         cin>>s;
         make(n)
         {
              if(s==a[i][0])
              {
                   if(a[i][0].size()>a[i][1].size())
                     cout<<a[i][1]<<" ";
               else
               cout<<a[i][0]<<" ";
              }
         }
    }
    
    
    
    
        
    
    
}