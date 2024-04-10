// Hydro submission #6332f8b85741ce022119302b@1664284857036
#include<iostream>
#include<cmath>
using namespace std;
int n,ans=1;//
int main(){
    cin>>n;//
    while(n>1){//
        ans=ans+n;//
        bool flag=true;//bool
        for(int i=2;i<=sqrt(n);i++){//
            if(n%i==0){//
                n=n/i;//n
                flag=false;//flagfalse
                break;//
            }
        }
        if(flag==true){//
            cout<<ans<<endl;return 0;//
        }
    }
    cout<<ans<<endl;//
    return 0;//
}