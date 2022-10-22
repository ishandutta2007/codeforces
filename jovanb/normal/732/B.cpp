#include <bits/stdc++.h>

using namespace std;
int niz[1000];
int main()
{
    int n,k,br=0,i;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>niz[i];
    }
    for(i=1;i<n;i++){
        br+=max(0,k-(niz[i]+niz[i-1]));
        niz[i]+=max(0,k-(niz[i]+niz[i-1]));
    }
    cout<<br<<endl;
    for(i=0;i<n;i++)cout<<niz[i]<<" ";
    return 0;
}