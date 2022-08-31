#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin>>s;
    char mn='z';
    for(char c:s){
        if(mn<c){
            cout<<"Ann"<<endl;
        }else{
            cout<<"Mike"<<endl;
        }
        mn=min(mn,c);
    }
    return 0;
}