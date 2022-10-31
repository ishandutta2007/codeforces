#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 15e4+7;
const int MAXN = 1e6+7;
int A[N],simp[N],P[MAXN];
int F(int x){
    return x==P[x]?x:P[x] = F(P[x]);
}
int unite(int a,int b){
    a = F(a);
    b = F(b);
    if (a==b)
        return 0;
    P[a] = b;
    return 1;
}
int ans[N*2];
void solve(){
    for(int i = 1;i<MAXN;++i)
        P[i] = i;
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        int x = A[i];
        for(int div = 2;div*div<=x;++div){
            if (x%div)
                continue;
            if (simp[i]==0)
                simp[i] = div;
            while(x%div==0)
                x/=div;
            unite(simp[i],div);
        }
        if (x!=1){
            int div = x;
            if (simp[i]==0)
                simp[i] = div;
            while(x%div==0)
                x/=div;
            unite(simp[i],div);
        }
    }
    map<pair<int,int>,vector<int> > M;
    for(int i = 1;i<=q;++i){
        int a,b;
        cin>>a>>b;
        a = F(simp[a]);
        b = F(simp[b]);
        if (a==b){
            ans[i] = 0;
        }
        else{
            ans[i] = 2;
            if (a>b)
                swap(a,b);
            M[{a,b}].push_back(i);
        }
    }
    for(int i = 1;i<=n;++i){
        int x = A[i]+1;

        vector<int> V;
        for(int div = 2;div*div<=x;++div){
            if (x%div)
                continue;
            while(x%div==0)
                x/=div;
            V.push_back(div);
        }
        if (x!=1)
            V.push_back(x);
        V.push_back(simp[i]);
        int sz = V.size();
        for(int i = 0;i<sz;++i){
            for(int j = i+1;j<sz;++j){
                int a = F(V[i]),b = F(V[j]);
                if (a>b)
                    swap(a,b);
                if (M.count({a,b})){
                    for(int to:M[{a,b}])
                        ans[to] = 1;
                    M.erase({a,b});
                }
            }
        }
    }
    for(int i = 1;i<=q;++i)
        cout<<ans[i]<<'\n';

}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}