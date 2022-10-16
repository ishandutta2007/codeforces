#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    n/=2;
    int a=0,b=0;
    int cnta=0,cntb=0;
    char c;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='?')cnta++;
        else a+=c-'0';
    }
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='?')cntb++;
        else b+=c-'0';
    }
    if((cnta+cntb)%2==1){cout<<"Monocarp"<<endl;return 0;}
    a-=b;
    cnta-=cntb;
    cnta*=-1;
    if(cnta*9==a*2)cout<<"Bicarp"<<endl;
    else cout<<"Monocarp"<<endl;
    return 0;
}