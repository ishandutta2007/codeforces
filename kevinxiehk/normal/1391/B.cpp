#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    string conv[n+5];
    for(int i=0;i<n;i++)cin>>conv[i];
    int cnt=0;
    for(int i=0;i<n-1;i++)if((conv[i])[m-1]=='R')cnt++;
    for(int i=0;i<m-1;i++)if((conv[n-1])[i]=='D')cnt++;
    cout<<cnt<<endl;
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}