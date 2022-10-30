#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ptr = 0;
    while(ptr+1<n){
        if (ptr==0 && s[ptr+1]>=s[ptr])
            break;
        if (ptr!=0 && s[ptr+1]>s[ptr])
            break;
        ++ptr;
    }
    for(int i = 0;i<=ptr;++i)
        cout<<s[i];
    for(int i = ptr;i>=0;--i)
        cout<<s[i];
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}