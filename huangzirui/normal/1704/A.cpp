#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m;
string S,T;
int main(){
    int Te;
    cin>>Te;
    while(Te--){
        cin>>n>>m;
        cin>>S>>T;
        bool B=true,r=false;
        for(int i=1;i<m;i++)
            if(T[m-i]!=S[n-i])B=false;
        for(int i=0;i<=n-m;i++)
            if(S[i]==T[0])r=true;
        if(r&B)puts("Yes");
        else puts("No");
    }
}