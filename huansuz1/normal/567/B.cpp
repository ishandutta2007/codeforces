#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int n , a[1234] , co , ma ,c[1234567] , z , ans , d[1234566];
char b[1234];
int main(){
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>b[i]>>a[i];
        if (b[i]=='+') { co++; c[a[i]]=1; ans=max(ans,co); } else 
            if (b[i]=='-' && c[a[i]]==1) {
                co--;
                c[a[i]]=0;
            } else ans++;
    }
    cout<<ans;

    return 0;
}