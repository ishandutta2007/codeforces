#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    int cnt[] = {0,0};
    for(int i = 1;i<=n;i+=1){
        int val;
        cin>>val;
        cnt[val%2] += 1;
    }
    cout<<min(cnt[0],cnt[1])<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}