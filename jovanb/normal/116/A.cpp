#include <bits/stdc++.h>
using namespace std;
int niz[200];
int main(){
    int n,maxi=0,g=0,i,a,b;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>b;
        g+=b-a;
        maxi=max(maxi,g);
    }
    cout<<maxi;
    return 0;
}