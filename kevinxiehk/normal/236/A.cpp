#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    bool have[30];
    for(int i=0;i<=26;i++)have[i]=false;
    for(int i=0;i<s.length();i++){
        have[s[i]-'a']=true;
    }
    int cnt=0;
    for(int i=0;i<=26;i++){
        if(have[i])cnt++;
    }
    if(cnt%2==0){
        cout<<"CHAT WITH HER!\n";
    }
    else{
        cout<<"IGNORE HIM!\n";
    }
    return 0;
}