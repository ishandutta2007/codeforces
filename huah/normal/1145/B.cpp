#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if((n>=13 && n<=29) || (n>=90 && n<=99) || n==10 || n==11 || (n>=70 && n<=79)){
        cout<<"NO"<<endl;
    }
    else if((n%10==1) || (n%10==7) || (n%10==9)){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}