#include<bits/stdc++.h>
using namespace std;
int n;
string s,t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>s>>t;
    int d1=(s[1]-s[0]+3)%3;
    int d2=(t[1]-t[0]+3)%3;
    cout<<"YES"<<endl;
    if(d1*d2%3==1){
        for(int i=1;i<=n*3;++i){
            cout<<(char)('a'+(-i*d1%3+3)%3);
        }
        cout<<endl;
    }else if(d1*d2%3==0){
        for(int i=1;i<=n*3;++i){
            cout<<(char)('a'+(-i*max(1,d1+d2)%3+3)%3);
        }
        cout<<endl;
    }else{
        for(int i=1;i<=n;++i){
            cout<<s[1];
        }
        for(int i=1;i<=n;++i){
            cout<<(char)('a'+'b'+'c'-s[0]-s[1]);
        }
        for(int i=1;i<=n;++i){
            cout<<s[0];
        }
        cout<<endl;
    }
    return 0;
}