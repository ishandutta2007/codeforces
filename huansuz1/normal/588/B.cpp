#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


long long n,x,y,m,ans=1;

int main(){
    cin>>n;

    for (int i=2; i*1ll*i<=n; i++)  
        if (n%i==0) {
            ans=ans*1ll*i;
            while(n%i==0)
                n/=i;
        }    
    
    if (n>1) ans*=n;

    cout<<ans;
    
    return 0;
}