#include <bits/stdc++.h>
using namespace std;
long long uzet[65];
long long pov[65];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long k,n,z=0,x=1,i;
    int mark=-1;
    cin>>n>>k;
    x=n;
    pov[0]=1;
    for(i=1;i<=61;i++)pov[i]=pov[i-1]*2;

    for(i=61;i>=0;i--){
        if(x>=pov[i]){
            if(mark==-1)mark=i;
            uzet[i]=1;
            z+=pov[i];
            x-=pov[i];
           }

    }
    if(k>1){
        for(i=mark;i>=0;i--)
            if(uzet[i]==0){
                z+=pov[i];
            }
    }
    cout<<z;
    return 0;
}