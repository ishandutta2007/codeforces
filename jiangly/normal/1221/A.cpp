#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            if(x<=2048){
                sum+=x;
            }
        }
        if(sum>=2048){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}