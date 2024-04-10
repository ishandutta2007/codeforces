#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MOD = 998244353;
const int N = 3e5+7;
int X[N],Y[N],vis[N];
pair<int,int> A[N];
ll res;
int n,m,k;
void calc(){
    map<int,int> M;
    int last = 1;
    int cur = 0;
    int ptr = 1;
    sort(A+1,A+1+k);
    for(int i = 1;i<=k;++i){
        while (ptr<n && A[i].first>=X[ptr+1])
            ++ptr;
        if (A[i].first==X[ptr]){
            vis[i] = 1;
            continue;
        }
        while(A[last].first<X[ptr]){
            if (!vis[last]){
                --cur;
                --M[A[last].second];
            }
            ++last;
        }
        ++cur;
        ++M[A[i].second];
        res+=cur-M[A[i].second];
    }
}
void solve(){

    cin>>n>>m>>k;
    for(int i = 1;i<=n;++i)
        cin>>X[i];
    for(int i = 1;i<=m;++i)
        cin>>Y[i];
    for(int i = 1;i<=k;++i){
        cin>>A[i].first>>A[i].second;
    }

    res = 0;
    calc();
    for(int i = 1;i<=k;++i)
        swap(A[i].first,A[i].second),vis[i] = 0;
    swap(X,Y);
    swap(n,m);
    calc();
    for(int i = 1;i<=k;++i)
        vis[i] = 0;
    cout<<res<<endl;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}