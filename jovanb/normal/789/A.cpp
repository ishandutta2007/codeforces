#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    cout.precision(10);
    cout<<fixed;

    long n,k,br=0,i,w;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>w;
        br+=w/k;
        if(w%k!=0)br++;
    }
    if(br%2==0)cout<<br/2;
    else cout<<br/2+1;
    return 0;
}