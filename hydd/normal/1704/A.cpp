#include<bits/stdc++.h>
using namespace std;
int T,n,m; string a,b;
bool check(){
    for (int i=1;i<m;i++)
        if (b[m-i]!=a[n-i]) return false;
    for (int i=0;i<=n-m;i++)
        if (a[i]==b[0]) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>T;
    while (T--){
        cin>>n>>m;
        cin>>a>>b;
        if (check()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}