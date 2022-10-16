#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s="";
    for(int i=0;i<n;i++)s+='9';
    int t=n-1;
    for(int i=1;i<=n;i+=4){
        s[t]='8';
        t--;
    }
    cout<<s<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}