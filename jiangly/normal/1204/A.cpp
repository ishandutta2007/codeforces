#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    bool ok=false;
    for(int i=1;i<s.length();++i){
        if(s[i]=='1'){
            ok=true;
        }
    }
    cout<<(s.length()+ok)/2<<endl;
    return 0;
}