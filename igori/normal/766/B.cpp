
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n=0;
    cin>>n;
     int m[100000]={4};
     for(int i=0; i<n; i++)
       cin>>m[i];
       sort(m, m+n);
    for(int i=0; i<n-2; i++)
      {
          if(m[i]+m[i+1]>m[i+2])
            {cout<<"YES"; return 0;} 
            
      }
    cout<<"NO";
     
}