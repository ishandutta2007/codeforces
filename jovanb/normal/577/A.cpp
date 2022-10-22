#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,x,br=0,i;
    cin>>n>>x;
    for(i=1;i*i<=x;i++){
        if(x%i==0){
            if(i<=n && x/i<=n){
                if(i*i==x)br++;
                else br+=2;
            }
        }
    }
    cout<<br;
    return 0;
}