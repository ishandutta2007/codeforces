#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,z=0,a,i;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a;
        z+=a;
        k-=min(8,z);
        z-=min(8,z);
        if(k<=0){cout<<i;return 0;}
    }
    cout<<-1;
    return 0;
}