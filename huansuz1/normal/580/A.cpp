#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <set>
#include <map>


typedef long long ll;

using namespace std;
int a[123456],n,m,b[123456],z=1,ans;


int main()
{
    cin>>n;
    
    for (int i=0; i<n; i++) 
        cin>>a[i];
    for (int i=1; i<n; i++)       
        if (a[i]>=a[i-1]) z++; else  {
            ans=max(z,ans);
            z=1;
        }
    ans=max(ans,z);
    cout<<ans;  
            

    
    
    
    
    return 0;
}