#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define then ;
#define cin(n); int n; cin>>n;
#define stop return 0;
//IgorI
//It is true or false
//Is it true or false?

//Codeforces 
//Problem 779A


int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n=0;
    for(int i=0; i<s.size(); i++)
    {
         if(s[i]=='0')
            n++;
    }
    if(n<k)
      {cout<<s.size()-1; return 0;}
    n=0;
    int ans=0;
    int i=s.size()-1;
    while(n<k)
    {
         if(s[i]=='0')
            n++;
         else ans++;
         i--;
      }
      
    cout<<ans;
        
    
    
}