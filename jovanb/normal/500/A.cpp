#include <bits/stdc++.h>
using namespace std;
int niz[100000];
int main()
{
    int n,t,i;
    cin>>n>>t;
    for(i=1;i<n;i++)cin>>niz[i];
    i=1;
    while(i<=n){
        if(i==t){cout<<"YES";return 0;}
        i+=niz[i];
        if(i==t){cout<<"YES";return 0;}
        if(i>t){cout<<"NO";return 0;}
    }
    return 0;
}