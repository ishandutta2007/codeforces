#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,is[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        string S;
        cin>>n;n<<=1;
        cin>>S;
        is[0]=0;
        int Num=0;k=0;
        for(i=1;i<=n;i++){
            if(S[i-1]=='('){
                k+=1-is[Num];
                is[Num]=1;
                ++Num;
                is[Num]=0;
            }else{
                --Num;
            }
        }cout<<k<<endl;
    }
}