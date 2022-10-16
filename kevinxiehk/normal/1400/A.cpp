#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)cout<<s[i*2];
    cout<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;

    cin>>t;
    
    while(t--)solve();
    return 0;
}