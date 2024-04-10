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
//Problem 747A


int main()
{
      int n;
      cin>>n;
      char s[1000];
      int A=0,C=0,G=0,T=0;
      for(int i=0; i<n; i++)
    {
         cin>>s[i];
         if(s[i]=='A')
            A++;
           if(s[i]=='C')
            C++;
            if(s[i]=='G')
            G++;
             if(s[i]=='T')
            T++;
    }
    if(n%4!=0)
    {
         cout<<"===";
         return 0;
        
    }
    if(max(max(A,C),max(G,T))>n/4)
    {
         cout<<"===";
         return 0;
    }
    int t=0;
    for(int i=0; i<n; i++)
    {
         if(s[i]!='?')
            cout<<s[i];
          else
          {
               t=0;
               if(A<n/4)
               {
                    A++;
                    cout<<'A';
                    t++;
               }
               if((C<n/4)&&(t==0))
               {
                    C++;
                    cout<<'C';
                    t++;
               }
               if((G<n/4)&&(t==0))
               {
                    G++;
                    cout<<'G';
                    t++;
               }
               if((T<n/4)&&(t==0))
               {
                    T++;
                    cout<<'T';
                    t++;
               }
          }
    }
    
    
    
    
    
    
    
        
    
    
}