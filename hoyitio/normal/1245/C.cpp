#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e5+7;
string s;
int dp[maxn];
int flag = 0;
int main(){
    cin>>s;
    int flag = 0;
    dp[0]=1;
    if(s[0]=='m'||s[0]=='w')flag = 1;
    for(int i=1;i<s.size();i++){
        dp[i]=dp[i-1];
        if(s[i]=='m'||s[i]=='w')flag = 1;
        if((s[i]=='u'&&s[i-1]=='u')||(s[i]=='n'&&s[i-1]=='n')){
            if(i==1){
                dp[i]=(dp[i]+1)%mod;
            }else{
                dp[i]=(dp[i]+dp[i-2])%mod;
            }
        }
    }
    if(flag==1){
        cout<<"0"<<endl;
    }else{
        cout<<dp[s.size()-1]%mod<<endl;
    }
}