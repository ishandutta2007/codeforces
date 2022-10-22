#include <bits/stdc++.h>

using namespace std;
int niz[1000];
int main()
{
    int n,br1=0,br2=0,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>niz[i];
        if(niz[i]%2==0)br2++;
        else br1++;
    }
    for(i=0;i<n;i++){
        if(niz[i]%2==0 && br2==1){cout<<i+1;return 0;}
        if(niz[i]%2==1 && br1==1){cout<<i+1;return 0;}
    }
    return 0;
}