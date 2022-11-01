#include <bits\stdc++.h>

using namespace std;

vector<int> a(100);
int main()
{
    int n,m;
    
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
       
     sort(a.rbegin(),a.rend());
     
     int have=0,i=0;
     for (;i<n;i++)
     {
         if (have>=m)
         break;
         
         have+=a[i];        
         
     }
       
      cout<<i;
    return 0;   
}