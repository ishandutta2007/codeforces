#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'
const int DIM = 2e6+7;
int add[DIM], ans[DIM];
bool vis[DIM];
void solve(){
    int n,m;
    cin>>n>>m;
    int prev = -m;
    int global = 0;
    for(int i = 1;i<=n;i+=1){
        for(int j = 1;j<=m;j+=1){

            int pos = (i-1)*m+j;
            char ch; cin>>ch;
            if (ch=='0'){
                ans[pos] = global;
                continue;
            }
            if (pos-prev>=m){
                global += 1;
            }
            else{
                int ts = min(n*m+1,m+1-(pos-prev+1)+pos);
                int te = min(n*m+1,m+pos);
                add[ts] += 1;
                add[te] -= 1;
            }
            if (!vis[j]){
                global += 1;
                vis[j] = 1;
            }
            ans[pos] = global;
            prev = pos;
        }
    }
    for(int i = m;i<=n*m;i+=1){
        add[i] += add[i-m];
    }

    for(int i = 1;i<=n*m;i+=1){
        add[i] += add[i-1];
        cout<<(add[i]+ans[i])<<' ';
    }
    for(int i = 0;i<=n*m+1;i+=1){
        ans[i] = add[i] = vis[i] = 0;
    }
    cout<<endl;
    return;
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