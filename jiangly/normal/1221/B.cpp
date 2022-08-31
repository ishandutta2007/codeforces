#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if((i+j)%2==0){
                cout<<"W";
            }else{
                cout<<"B";
            }
        }
        cout<<endl;
    }
    return 0;
}