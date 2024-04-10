#include <bits/stdc++.h>

using namespace std;
string s;int n,ans;
int main()
{
    cin>>s;n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='Q'){
        for(int j=i+1;j<n;j++)if(s[j]=='A'){
        for(int z=j+1;z<n;z++)if(s[z]=='Q')ans++;}}

    }
cout<<ans;
    return 0;
}