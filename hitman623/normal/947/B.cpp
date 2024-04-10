#include <bits/stdc++.h>

#define int         long long
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
int n,t[100005],v[100005],p[100005],ans[100005];
const int N=100005;
int a[N],seg[4*N],lazy[4*N];
void build(int node,int start,int end){
    if(start==end){
        seg[node]=a[start];
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg[node]=seg[node<<1]+seg[node<<1|1];
}
void update(int node,int start,int end,int l,int r,int val){
    if(lazy[node]!=0){
        seg[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || start>r || end<l) return;
    if(l<=start && end<=r){
        seg[node]+=(end-start+1)*val;
        if(start!=end){
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
        }
        return;
    }
    int mid=(start+end)>>1;
    update(node<<1,start,mid,l,r,val);
    update(node<<1|1,mid+1,end,l,r,val);
    seg[node]=seg[node<<1]+seg[node<<1|1];
}
int query(int node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return 0;
    if(lazy[node]!=0){
        seg[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=l && end<=r) return seg[node];
    int mid=(start+end)>>1;
    int q1=query(node<<1,start,mid,l,r);
    int q2=query(node<<1|1,mid+1,end,l,r);
    return q1+q2;
}
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>v[i];
    }
    rep(i,0,n){
        cin>>t[i];
        p[i]=t[i]+(i?p[i-1]:0);
    }
    rep(i,0,n){
        int h=v[i]+(i?p[i-1]:0);
        int l=lower_bound(p+i,p+n,h)-p;
        if(p[l]==h){
            update(1,0,n-1,i,l,1);
        }
        else{
            update(1,0,n-1,i,l-1,1);
            ans[l]+=h-p[l-1];
        }
    }
    rep(i,0,n){
        ans[i]+=query(1,0,n-1,i,i)*t[i];
        cout<<ans[i]<<" ";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    // cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}