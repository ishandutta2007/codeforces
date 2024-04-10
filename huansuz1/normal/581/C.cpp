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
int a[123456],n,m,b[123456];
ll ans;


int main()
{
    cin>>n>>m;
    int p=n;
    for (int i=0; i<n; i++) {
        cin>>a[i];          
        ans+=a[i]/10;   
        b[i]=a[i]%10;
    }
    sort(b,b+n);

    while(n!=0){
        n--;
        if (m>=(10-b[n])) { m-=(10-b[n]); ans++;}
    }

    ans+=(m/10);
    if (ans>p*10) ans=p*10;
    cout<<ans;
        
    
    
    
    
    return 0;
}