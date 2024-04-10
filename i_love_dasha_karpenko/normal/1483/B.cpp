#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
int A[N],vis[N];
void solve(){
    int n;
    cin>>n;
    set<int> order;
    vector<pair<int,int> > cand;
    for(int i = 1;i<=n;++i){
        order.insert(order.end(),i);
        cin>>A[i];
        if (i>1 && __gcd(A[i],A[i-1])==1)
            cand.push_back({i-1,i});
    }
    if (__gcd(A[1],A[n])==1)
        cand.push_back({n,1});
    vector<int> ans;
    while(!cand.empty()){
        vector<pair<int,int> > del;
        for(pair<int,int> to:cand){
            if (vis[to.first]==0){
                vis[to.second] = 1;
                ans.push_back(to.second);
                int a = to.first,b;
                if (to.second == *order.rbegin()){
                    b = *order.begin();
                }
                else{
                    b = *order.upper_bound(to.second);
                }
                if (__gcd(A[a],A[b])==1){
                    del.push_back({a,b});
                }
                order.erase(to.second);
            }
        }
        swap(cand,del);
    }

    for(int i = 1;i<=n;++i){
        vis[i] = 0;
    }
    cout<<ans.size()<<' ';
    for(int to:ans)
        cout<<to<<' ';
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}