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
const int N = 2e5+7;
int A[N],n;
int Check(int col){
    vector<int> V;
    for(int i = 1;i<=n;++i){
        if (A[i]==col)
            continue;
        V.push_back(A[i]);
    }
    int sz = V.size();
    for(int i = 0;i<sz-i-1;++i){
        if (V[i]!=V[sz-1-i])
            return 0;
    }
    return 1;
}
void solve(){
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    pair<int,int> c = {-1,-1};
    for(int i = 1;i<n+1-i;++i){
        if (A[i]!=A[n+1-i]){
            c = {A[i],A[n+1-i]};
            break;
        }
    }
    int flag = 1;
    if (c.first!=-1)
        flag = max(Check(c.first),Check(c.second));
    if (flag)
        cout<<"YES\n";
    else cout<<"NO\n";
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