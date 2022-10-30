#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//#define endl '\n'
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
const int INF = 1e18;
const int N = 1e4+7;
int ask(int pos){
    cout<<"? "<<pos<<endl;
    int ret;
    cin>>ret;
    return ret;
}
bool vis[N];
int ans[N];
void solve() {
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        ans[i] = vis[i] = 0;
    for(int i = 1;i<=n;++i){
        if (vis[i])
            continue;
        int prev = ask(i);
        int start = prev;
        do{
            int next = ask(i);
            ans[prev] = next;
            vis[next] = 1;
            prev = next;
        }while(prev!=start);
    }
    cout<<"! ";
    for(int i = 1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<endl;

}
int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}