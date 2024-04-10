#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 107;
const int AL = 26;
bool vis[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i+=1){
        vis[i] = 0;
    }
    if (n==1){
        int val; cin>>val;
        cout<<"-1\n";
        return;
    }
    for(int i = 1;i<=n-2;i+=1){
        int cur;
        cin>>cur;
        for(int j = 1;j<=n;j+=1){
            if (j!=cur && vis[j]==0){
                cout<<j<<' ';
                vis[j] = 1;
                break;
            }
        }
    }
    int plast,last;
    cin>>plast>>last;
    vector<int> fr;
    for(int j = 1;j<=n;j+=1){
        if (!vis[j]){
            fr.push_back(j);
        }
    }
    if (fr[0]==plast || fr[1]==last){
        swap(fr[0],fr[1]);
    }
    for(int to:fr){
        cout<<to<<' ';
    }
    cout<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}