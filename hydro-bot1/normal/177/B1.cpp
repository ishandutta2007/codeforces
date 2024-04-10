// Hydro submission #62c59e378672efa577bf0dac@1657118264576
#include<iostream>
#include<cmath>
using namespace std;
int n,ans=1;
int main(){
    cin>>n;
    while(n>1){
        ans=ans+n;
        bool flag=true;
        for(int i=n-1;i>=sqrt(n);i--){
            if(n%i==0){
                n=i;flag=false;
                break;
            }
        }
        if(flag==true){
            cout<<ans<<endl;return 0;
        }
    }
    cout<<ans<<endl;
}