#include <bits/stdc++.h>

using namespace std;
int m[400];
int main()
{
    long long p,n,i,a;
    cin>>p>>n;
    for(i=1;i<=n;i++){
        cin>>a;
        m[a%p]++;
        if(m[a%p]>1){cout<<i;return 0;}
    }
    cout<<-1;
    return 0;
}