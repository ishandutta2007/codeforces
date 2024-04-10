#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int n,m,k,z,a[321321],b[123321],c[123321],p,t=1;
map<long long , int> mp;


int main()
{   cin>>n;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=n-1; i>=0; i--) {
        p=max(p,a[i]);
        b[i]=p;
        mp[p]++;
        if (mp[p]==1 && b[i]==a[i]) c[z++]=0; else c[z++]=(b[i]-a[i])+1;
    }
    for (int i=z-1; i>=0; i--)
        cout<<c[i]<<" ";


        
        
    
    
    return 0;
}