#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,p[100005],ans,N=100000;
int t[200005],lis[100005],lds[100005];
void modify(int P,int val){
    for(t[P+=N]=val;P>1;P>>=1) t[P>>1]=max(t[P],t[P^1]);
}
int query(int l,int r){
    int res=0;
    for(l+=N,r+=N+1;l<r;l>>=1,r>>=1){
        if(l&1) res=max(res,t[l++]);
        if(r&1) res=max(res,t[--r]);
    }
    return res;
}
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        int L,R;
        cin>>L>>R;
        p[L]++;
        p[R+1]--;
    }
    rep(i,1,m+1){
        p[i]+=p[i-1];
    }
    for(int i=1;i<=m;i++){
        lis[i]=query(0,p[i])+1;
        modify(p[i],lis[i]);
    }
    memset(t,0,sizeof t);
    for(int i=m;i>=1;--i){
        lds[i]=query(0,p[i])+1;
        modify(p[i],lds[i]);
    }
    rep(i,1,m+1){
        ans=max(ans,lis[i]+lds[i]-1);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}