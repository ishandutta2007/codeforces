
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int m[1000000];
string s;

int main()
{
    cin>>s;
    int t=0;
    n=s.size();
    if(n%2==1)
    {
        for(int i=0; i<n/2; i++)
           {
               if(s[i]!=s[n-i-1])
               {  t++; }
           }   
           if(t<2)
             cout<<"YES";
           else
             cout<<"NO";
    }
    if(n%2==0)
    {for(int i=0; i<n/2; i++)
           {
               if(s[i]!=s[n-i-1])
               {  t++;}
           }  
           if(t==1)
             cout<<"YES";
           else
             cout<<"NO";
    }
    
}