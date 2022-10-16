#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
void solve(){
    string s,ss;
    cin>>s>>ss;
    map<char,bool>m;
    for(int i=0;i<s.length();i++){
        m[s[i]]=1;
    }
    for(int i=0;i<s.length();i++){
        if(m[ss[i]]==1){cout<<"YES"<<endl;return;}
    }
    cout<<"NO"<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}