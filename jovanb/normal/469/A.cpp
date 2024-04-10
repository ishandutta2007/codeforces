#include <bits/stdc++.h>

using namespace std;
int niz[1000];
int main()
{
    int n,x,a,i;
    cin>>n;
    cin>>x;
    for(i=0;i<x;i++){
        cin>>a;
        niz[a]=1;
    }
    cin>>x;
    for(i=0;i<x;i++){
        cin>>a;
        niz[a]=1;
    }
    for(i=1;i<=n;i++){
        if(niz[i]==0){cout<<"Oh, my keyboard!";return 0;}
    }
    cout<<"I become the guy.";
    return 0;
}