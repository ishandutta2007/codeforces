#include <bits/stdc++.h>
using namespace std;

pair <string,string> par[200];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,i;
    cin>>n;
    for(i=0;i<n;i++)cin>>par[i].first>>par[i].second;
    for(i=0;i<n;i++){
        if(par[i].second=="rat")cout<<par[i].first<<endl;
    }
    for(i=0;i<n;i++){
        if(par[i].second=="woman" || par[i].second=="child")cout<<par[i].first<<endl;
    }
    for(i=0;i<n;i++){
        if(par[i].second=="man")cout<<par[i].first<<endl;
    }
    for(i=0;i<n;i++){
        if(par[i].second=="captain")cout<<par[i].first<<endl;
    }
    return 0;
}