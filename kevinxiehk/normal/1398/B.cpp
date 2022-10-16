#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    string s;
    cin>>s;
    priority_queue<int>aaa;
    int now=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            now++;
        }
        else{
            aaa.push(now);
            now=0;
        }
    }
    aaa.push(now);
    int ans=aaa.top();
    aaa.pop();
    while(aaa.size()>=2){
        aaa.pop();
        ans+=aaa.top();
        aaa.pop();
    }
    cout<<ans<<endl;
    while(!aaa.empty())aaa.pop();
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}