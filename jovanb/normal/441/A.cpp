#include <bits/stdc++.h>
using namespace std;

queue <long> kju;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n;
    long v,x,mini=1000000,k,j,i,br=0;
    cin>>n>>v;
    for(i=1;i<=n;i++){
        cin>>x;
        mini=1000000;
        for(j=0;j<x;j++){
            cin>>k;
            mini=min(mini,k);
        }
        if(v>mini){
            br++;
            kju.push(i);
        }
    }
    cout<<br<<"\n";
    while(!kju.empty()){
        cout<<kju.front()<<" ";
        kju.pop();
    }
    return 0;
}