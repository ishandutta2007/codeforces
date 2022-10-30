#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
void solve(){
    int n;
    cin>>n;
    map<int,int> M;
    for(int i = 1;i<=n;++i){
        int val;
        cin>>val;
        M[abs(val)]++;
    }
    int res = 0;
    for(auto [val,cnt]:M){
        res+=1+(cnt>1 && val>0);
    }
    cout<<res<<endl;
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