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
int tree[20][200005],A[200005];
void build(int h,int l,int r){
    if(l==r) tree[h][l]=A[l];
    else{
        int m=(l+r)>>1;
        build(h+1,l,m);
        build(h+1,m+1,r);
        merge(tree[h+1]+l,tree[h+1]+m+1,tree[h+1]+m+1,tree[h+1]+r+1,tree[h]+l);
    }
}
int query(int h,int l,int r,int a,int b,int val){
    if(r<a || l>b || b<a) return 0;
    if(a<=l && r<=b) return r-l+1-(lower_bound(tree[h]+l,tree[h]+r+1,val)-tree[h]-l);
    int m=(l+r)>>1;
    return query(h+1,l,m,a,b,val)+query(h+1,m+1,r,a,b,val);
}
void solve(){
    int n;
    ll ans=0;
    cin>>n;
    rep(i,0,n){
        cin>>A[i];
    }
    build(0,0,n-1);
    rep(i,0,n){
        ans=ans+query(0,0,n-1,i+1,max(i,min(A[i]-1,n-1)),i+1);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}