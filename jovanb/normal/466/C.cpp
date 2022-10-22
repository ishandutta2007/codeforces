#include <bits/stdc++.h>

using namespace std;
long long niz[500005];
short moze[500005];
long long s[500005];
int main()
{
    long n,i;
    long long x,z=0,u=0,v=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
        z+=niz[i];
    }
    if(z%3!=0){cout<<0;return 0;}
    z/=3;
    for(i=n-1;i>=0;i--){
        u+=niz[i];
        if(u==z)moze[i]=1;
    }
    s[n-1]=moze[n-1];
    for(i=n-2;i>=0;i--)s[i]=s[i+1]+moze[i];
    u=0;
    for(i=0;i<n-2;i++){
        u+=niz[i];
        if(u==z)v+=s[i+2];
    }
    cout<<v;
    return 0;
}