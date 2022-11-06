#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,s;cin>>n;
        if(n==1)s=2;
        else if(n%3==0)s=n/3;
        else s=n/3+1;
        cout<<s<<endl;
    }
    return 0;
}