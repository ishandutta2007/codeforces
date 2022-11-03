#include <bits/stdc++.h>

using namespace std;

int main(){
    int ans=0;
    int n,k;
    cin>>n>>k;
    k=240-k;
    while ((ans+2)*(ans+1)/2<=k/5) ans++;
    cout<<min(ans,n);
}