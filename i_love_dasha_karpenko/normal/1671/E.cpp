#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<ctime>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define endl '\n'
typedef long long ll;

const int N = 1<<19;
const int MOD = 998244353;
bool A[N];
int n;
ll clk(int v,vector<bool> &root){
    if (v*2+1>n){
        root.push_back(A[v]);
    
        return 1;
    }
    vector<bool> L,R;
    ll cl = clk(v*2,L);
    ll cr = clk(v*2+1,R);
    bool eqv = 1,le = 0;
    int len = L.size();
    for(int i = 0;i<len;++i){
        if (L[i]!=R[i]){
            if (L[i]<R[i]){
                le = 0;
            }
            else{
                le = 1;
            }
            eqv = 0;
            break;
        }
    }
    if (le){
        swap(L,R);
    }
    root.resize(len*2+1);
    int ptr = 0;
    for(auto to:L){
        root[ptr++] = to;
    }
    root[ptr++] = A[v];
    for(auto to:R){
        root[ptr++] = to;
    }
    
    if (eqv){
        return (cl*cr)%MOD;
    }
    else{
        return (cl*cr)*2%MOD;
    }
}
void solve(){
    int lev; 
    cin>>lev;
    n = (1<<lev)-1;
    for(int i = 1;i<=n;++i){
        char ch; cin>>ch; A[i] = ch=='A';
    }
    
    vector<bool> dum;
    cout<<clk(1,dum)<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}