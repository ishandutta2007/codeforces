#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,is[27];
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(is,0,sizeof(is));
        cin>>S;
        int CNT=0;
        for(i=S.size()-1;i>=0;i--){
            is[S[i]-'a']++;
            if(is[S[i]-'a']==1)CNT=i;
        }
        for(j=CNT;j<S.size();j++)putchar(S[j]);
        puts("");
    }
}