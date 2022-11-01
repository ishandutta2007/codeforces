
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;

void solve(){
    int n,c;cin>>n>>c;
    map<int,int>cnt;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        cnt[x]++;
    }
    int res=0;
    for (auto cur:cnt) res+=min(c,cur.second);
    cout<<res<<'\n';



}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}