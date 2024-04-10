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
    int a[6]={0};
    int b[6]={0};
    int k=0;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>k;
        a[k]++;
    }
    for(int i=0; i<n; i++)
    {
        cin>>k;
        b[k]++;
    }
    int t=0;
    for(int i=1; i<=5; i++)
    {
        if((a[i]+b[i])%2!=0)
           {
               cout<<-1; return 0;
           }
        t=t+ ( max(a[i],b[i]) - min(a[i],b[i]) )/2;
    }
    cout<<t/2; 
    
        
    
    
}