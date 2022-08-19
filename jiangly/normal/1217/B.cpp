#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n,x;
        cin>>n>>x;
        int mx=0;
        int md=0;
        for(int i=0;i<n;++i){
            int d,h;
            cin>>d>>h;
            mx=max(mx,d);
            md=max(md,d-h);
        }
        if(mx<x&&md==0){
            cout<<-1<<endl;
        }else if(mx>=x){
            cout<<1<<endl;
        }else{
            cout<<1+(x-mx+md-1)/md<<endl;
        }
    }
    return 0;
}