#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        int tmp=0,tmp2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(a[i]%2!=0) tmp=1;
            }
            else{
                if(a[i]%2==0) tmp2=1;
            }
        }
        if(n%2==0){
            if(tmp2==1) cout<<2<<endl;
            else cout<<1<<endl;
        }
        else{
            if(tmp==1) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
}