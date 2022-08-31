#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(char c:s){
        if(c=='n'){
            ++cnt;
        }
    }
    for(int i=0;i<cnt;++i){
        cout<<1<<' ';
    }
    for(int i=0;i<(n-3*cnt)/4;++i){
        cout<<0<<' ';
    }
    cout<<endl;
    return 0;
}