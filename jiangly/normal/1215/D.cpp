#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int s1=0,s2=0;
    int c1=0,c2=0;
    for(int i=0;i<n/2;++i){
        if(isdigit(s[i])){
            s1+=s[i]-'0';
        }else{
            ++c1;
        }
    }
    for(int i=n/2;i<n;++i){
        if(isdigit(s[i])){
            s2+=s[i]-'0';
        }else{
            ++c2;
        }
    }
    if(s1*2+c1*9==s2*2+c2*9){
        cout<<"Bicarp"<<endl;
    }else{
        cout<<"Monocarp"<<endl;
    }
    return 0;
}