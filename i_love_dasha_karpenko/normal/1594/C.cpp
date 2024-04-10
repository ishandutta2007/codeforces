//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("funroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 3e5+7;
bool SP[N];
vector<int> simp;
int vis[N];
void add(int x){
    for(int i = 1;i*i<=x;++i){
        if (x%i)
            continue;
        vis[i] = vis[x/i] = 1;
    }
}
void solve(){
    int n;
    cin>>n;
    char need;
    cin>>need;
    int res = 2,ans = -1,flag = 0;
    for(int i = 1;i<=n;++i){
        char ch;
        cin>>ch;
        if (ch!=need){
            add(i);
            flag = 1;
        }
    }
    if (!flag){
        cout<<"0\n";
        return;
    }
    for(int i = 2;i<=n;++i){
        if (vis[i]==0){
            res = 1;
            ans = i;
            break;
        }
    }
    if (res==1){
        cout<<res<<endl<<ans<<endl;
    }
    else{
        cout<<2<<endl;
        for(int i = n;i>=1;--i){
            if (SP[i]==1)
                continue;
            cout<<i<<' ';
            --res;
            if (res==0)
                break;
        }
    }
    for(int i = 1;i<=n;++i)
        vis[i] = 0;

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 2;i<N;++i){
        if (SP[i])
            continue;
        simp.push_back(i);
        if (ll(i)*i<N)
            for(int j = i*i;j<N;j+=i)
                SP[j] = 1;
    }
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}