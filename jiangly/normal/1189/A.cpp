// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin>>n>>s;
    int cnt=0;
    for(int i=0;i<n;++i){
        cnt+=(s[i]=='1');
    }
    if(cnt*2==n){
        cout<<2<<endl;
        cout<<s[0]<<' '<<s.substr(1,n-1)<<endl;
    }else{
        cout<<1<<endl;
        cout<<s<<endl;
    }
    return 0;
}