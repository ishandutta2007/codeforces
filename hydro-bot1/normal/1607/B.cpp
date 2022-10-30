// Hydro submission #61ab1793ef9a89de1e761048@1638602644353
#include<bits/stdc++.h>
using namespace std;
int main(){
    int times;
    cin>>times;
    while(times--){
        long long x,n,k=1;
        cin>>x>>n;
        if(x%2) k=-1;
        if(n%2){
            long long qq=n-1;
            if(qq%4){
                x+=k;
            }
            if(x%2){
                x+=n;
                cout<<x<<endl;
            }
            else{
                x-=n;
                cout<<x<<endl;
            }
        }
        else{
            if(n%4){
                x+=k;
                cout<<x<<endl;
            }
            else cout<<x<<endl;
        }
    }
    return 0;
}