#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,T;
int main(){
    cin>>T;
    while(T--){
        string S;
        cin>>S;n=S.size();
        if(n==1)cout<<S<<endl;
        else if(n==2)cout<<S[1]<<endl;
        else{
            char c='9';
            for(i=0;i<n;i++)c=min(c,S[i]);
            cout<<c<<endl;
        }
    }
}