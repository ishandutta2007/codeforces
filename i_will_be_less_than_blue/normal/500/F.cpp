
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=4010;
const int T=20010;
const int L=20;
const ll mod=998244353;
const ll inf=2000000000000000001;
int c[N],h[N],t[N];
vector<pair<int,int> >Q[T];
vector<pair<int,int> >node[T*4];
void upd(int v,int l,int r,int L,int R,pair<int,int>x){

    if (l>R || r<L) return;
    if (l>=L && r<=R){
        node[v].push_back(x);

//        cout<<"OK "<<l<<" "<<r<<endl;
        return;
    }
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
}
int dp[N];
int ans[T];
void dfs(int v,int l,int r){
    vector<int>dp1;
    for (int i=0;i<N;i++) dp1.push_back(dp[i]);
    for (auto cur:node[v]){
//        cout<<"OK "<<cur.first<<" "<<cur.second<<endl;
        for (int i=N-1;i>=cur.first;i--){
            dp[i]=max(dp[i],dp[i-cur.first]+cur.second);
        }
    }
    if (l==r){
       for (auto cur:Q[l]){
//           cout<<cur.first<<" "<<cur.second<<" "<<dp[cur.first]<<endl;
            ans[cur.second]=dp[cur.first];
       }
//        cout<<"A "<<l<<endl;

    } else {
        int m=(l+r)/2;
        dfs(v+v,l,m);
        dfs(v+v+1,m+1,r);
    }


    for (int i=0;i<N;i++) dp[i]=dp1[i];
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,p;cin>>n>>p;
    for (int i=1;i<=n;i++) cin>>c[i]>>h[i]>>t[i];
    for (int i=1;i<=n;i++){
        upd(1,1,20000,t[i],t[i]+p-1,{c[i],h[i]});
    }
    int q;cin>>q;
    for (int i=1;i<=q;i++){
        int a,b;cin>>a>>b;
        Q[a].push_back({b,i});
    }
    dfs(1,1,20000);

    for (int i=1;i<=q;i++) cout<<ans[i]<<endl;
    return 0;
}

/*
1
5
3 2 1 4 5
0 1 1 1 0
*/