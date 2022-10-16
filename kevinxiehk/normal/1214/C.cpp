#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    if(n%2==1){cout<<"No"<<endl;return 0;}
    int cnt=0,mistake=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(')cnt++;
        else{
            if(cnt==0)mistake++;
            else cnt--;
        }
    }
    if(cnt==mistake&&mistake<=1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}