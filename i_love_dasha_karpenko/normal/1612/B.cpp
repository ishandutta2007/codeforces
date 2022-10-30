//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gdb cout<<"dolboeb"<<endl;
const int N = 107;
int vis[N];
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    for(int i = 1;i<=n;++i)
        vis[i] = 0;
    if (b<a-1){
        cout<<"-1\n";
        return;
    }
    int nb = a-1,na = n-b;
    int mid = n>>1;

    vector<int> ans;
    for(int i = n;i>=1;--i){
        if (i==b || i==a)
            continue;
        if (ans.size()==mid-1)
            break;
        ans.push_back(i);
        vis[i] = 1;
    }
    vis[a] = 1;
    ans.push_back(a);
    for(int i = 1;i<=n;++i)
        if (!vis[i])
            ans.push_back(i);
    int mi = n;
    for(int i = 0;i<mid;++i)
        mi = min(mi,ans[i]);
    int mx = 0;
    for(int i = mid;i<n;++i)
        mx = max(mx,ans[i]);
    if (mx!=b || mi!=a){
        cout<<"-1\n";
        return;
    }
    for(int to:ans)
        cout<<to<<' ';
    cout<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}