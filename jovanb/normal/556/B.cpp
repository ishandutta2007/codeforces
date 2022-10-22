#include <bits/stdc++.h>
using namespace std;

int niz[1000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)cin>>niz[i];
    for(i=0;i<n;i++){
        if(niz[i]!=i)break;
        if(i==n-1){cout<<"Yes";return 0;}
    }
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            if(i%2==0)niz[i]++;
            else niz[i]--;
            if(niz[i]<0)niz[i]=n-1;
            if(niz[i]>=n)niz[i]=0;
        }
        for(i=0;i<n;i++){
            if(niz[i]!=i)break;
            if(i==n-1){cout<<"Yes";return 0;}
        }
    }
    cout<<"No";
    return 0;
}