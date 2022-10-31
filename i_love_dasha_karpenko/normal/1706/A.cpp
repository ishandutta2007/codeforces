//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
//#define int ll
const int N = 57;
bool vis[N];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i+=1){
        vis[i] = 0;
    }
    for(int i = 1;i<=n;i+=1){
        int pos;
        cin>>pos;
        if (m-pos+1<pos){
            pos = m-pos+1;
        }
        if (vis[pos]){
            pos = m-pos+1;
        }
        vis[pos] = 1;
    }
    for(int i = 1;i<=m;i+=1){
        cout<<(vis[i]?'A':'B');
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}