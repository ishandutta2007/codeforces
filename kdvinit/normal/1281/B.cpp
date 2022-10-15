#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

string letsmakeitsmallest(string a){
    int in = 0;
    int n = a.size();
    int j=0;
    for(j = 0;j < n; j++){
        char minn = a[j];
        int tmp=0;
        for(int i = j + 1;i < n; i++){
            if(a[i]<minn || (a[i]==minn && tmp==1) ){
                minn = a[i];
                in = i;
                tmp=1;
            }
        }
        if(tmp==1) goto yes;
    }
    yes:
    if(j!=n) swap(a[j],a[in]);
    return a;
}

bool letsnowcompare(string a, string b){
    int i = 0;
    int n = a.size(),m = b.size();
    for(i = 0;i < min(n,m); i++){
        if(a[i]!=b[i]){
            if(a[i]>b[i]) return false;
            if(a[i]<b[i]) return true;
        }
    }
    if(i==n&&n<m) return true;
    return false;
}

void solve()
{
    string a,b;
    cin>>a>>b;
    a = letsmakeitsmallest(a);
    if(letsnowcompare(a,b)) cout<<a<<endl;
    else cout<<"---"<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}