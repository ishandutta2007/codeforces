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

int n, x, m,a[345678],z,b[12345],ans;
char ch;

int main() {
    cin>>n;  
    if (n==1) {cout<<0; return 0;}
    a[z++]=2;
    a[z++]=3;
    a[z++]=5;
    for (int i=7; i<=1000; i++)  {
        int p=0;
        for (int j=2; j*j<=i; j++)
            if (i%j==0) {p=1; break; }
        if (p==0) a[z++]=i;
    }

    for (int i=0; i<z; i++){
        if (a[i]<=n){
            int q=1;
            for (int j=0; j<=123; j++)    {
                q*=a[i];
                if (q<=n) b[ans++]=q; else break;

            }
        }
    }
    cout<<ans<<endl;
    for (int i=0; i<ans; i++)
        cout<<b[i]<<" ";



    return 0;
}