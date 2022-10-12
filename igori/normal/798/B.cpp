
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
string s[100];
//string s1[100];
string buka;



int main()
{
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++)
      {  cin>>s[i]; 
     // s1[i]=s[i]+s[i];
     }
      
     int k=s[0].size();
     
     int now=0;
     int ans=99999999;
     int t=0;
     
     string au;
     
     int mt=0;
     
     for(int i=0; i<n; i++)
     {
         buka=s[i];
         now=0;
         for(int j=0; j<n; j++)
         {
             au=s[j]+s[j];
             mt=0;
             for(int ii=0; ii<k; ii++)
             {
                 t=1;
                 for(int jj=0; jj<k; jj++)
                 {
                     if(buka[jj]!=au[ii+jj])
                     {
                         t=0;
                         break;
                     }
                 }
                 if(t==1)
                 {
                     now+=ii;
                     mt=1;
                     break;
                 }
                 
             }
             if(mt==0)
             {
                 cout<<-1;
                 return 0;
             }
         }
         if(now<ans)
         ans=now;
     }
     cout<<ans;
     

    
}