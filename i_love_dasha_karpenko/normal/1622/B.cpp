#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int N = 2e5+7;
int ans[N],P[N];
void solve() {
    int n;
    cin>>n;

    for(int i = 1;i<=n;++i){
        cin>>P[i];
    }
    vector<pair<int,int> > V[2];
    for(int i = 1;i<=n;++i){
        char ch; cin>>ch;
        V[ch=='1'].push_back({P[i],i});
    }
    int ptr = n;
    for(int col = 1;col>=0;--col){
        sort(all(V[col]),greater<pair<int,int>>());
        for(auto [val,pos]:V[col]){
            ans[pos] = ptr--;
        }
    }
    for(int i = 1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}