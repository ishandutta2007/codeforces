#include <bits/stdc++.h>

using namespace std;
long h[150005];
long res[150005];
int main()
{
    long n,k,resmin,i;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>h[i];
    }
    for(i=0;i<k;i++){
        res[0]+=h[i];
    }
    resmin=res[0];
    for(i=1;i<n-k+1;i++){
        res[i]=res[i-1]-h[i-1]+h[i+k-1];
        resmin=min(resmin,res[i]);
    }
    for(i=0;i<n;i++){
        if(resmin==res[i]){cout<<i+1;return 0;}
    }
    return 0;
}