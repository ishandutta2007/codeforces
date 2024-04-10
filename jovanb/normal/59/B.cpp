#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,x,br=1000,brn=0,z=0,i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        z+=x;
        if(x%2!=0){
            br=min(x,br);
            brn++;
        }
    }
    if(br==1000)br=z;
    if(brn%2==0)z-=br;
    cout<<z;
    return 0;
}