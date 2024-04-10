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
#define N           30000000
#define left        LEFT
#define right       RIGHT
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,b[200005],q;
int sparse_on_b[20][200005];
int log2s[200005];
int tree[N],lazy[N],left[N],right[N],root=1;
void pre(){
    rep(i,1,20){
        rep(j,1,2*n+1){
            sparse_on_b[i][j]=min(sparse_on_b[i-1][j],sparse_on_b[i-1][max(1,min(2*n,j+(1<<i)-1)-(1<<(i-1))+1)]);
        }
    }
}
int query_on_b(int l,int r){
    if(r-l+1>=n) return sparse_on_b[19][1];
    l=(l-1)%n+1;
    r=(r-1)%n+1;
    if(l>r) r+=n;
    int d=log2s[(r-l+1)];
    return min(sparse_on_b[d][l],sparse_on_b[d][r-(1<<d)+1]);
}
int get_left(int node){
    if(left[node]==0) left[node]=++root;
    return left[node];
}
int get_right(int node){
    if(right[node]==0) right[node]=++root;
    return right[node];
}
void update(ll node,int start,int end,int l,int r,int x){
    if(lazy[node]){
        tree[node]=lazy[node];
        if(start!=end){
            lazy[get_left(node)]=lazy[node];
            lazy[get_right(node)]=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || start>r || end<l){
        if(tree[node]==0) tree[node]=query_on_b(start,end);
        return;
    }
    if(l<=start && end<=r){
        tree[node]=x;
        if(start!=end){
            lazy[get_left(node)]=x;
            lazy[get_right(node)]=x;
        }
        return;
    }
    int mid=(start+end)/2;
    update(get_left(node),start,mid,l,r,x);
    update(get_right(node),mid+1,end,l,r,x);
    tree[node]=min(tree[get_left(node)],tree[get_right(node)]);
}
int query(ll node,int start,int end,int l,int r){
    if(start>end || start>r || end<l) return hell;
    if(lazy[node]){
        tree[node]=lazy[node];
        if(start!=end){
            lazy[get_left(node)]=lazy[node];
            lazy[get_right(node)]=lazy[node];
        }
        lazy[node]=0;
    }
    if(l<=start && end<=r){
        if(tree[node]==0) tree[node]=query_on_b(start,end);
        return tree[node];
    }
    int mid=(start+end)/2;
    return min(query(get_left(node),start,mid,l,r),query(get_right(node),mid+1,end,l,r));
}
void solve(){
    cin>>n>>k;
    rep(i,1,n+1) cin>>b[i];
    log2s[0]=-1;
    rep(i,1,2*n+1){
        if(i>n) b[i]=b[i-n];
        sparse_on_b[0][i]=b[i];
        log2s[i]=log2s[i-1];
        if((i&(i-1))==0) log2s[i]++;
    }
    pre();
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r,x;
            cin>>l>>r>>x;
            update(1,1,n*k,l,r,x);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n*k,l,r)<<endl;
        }
    }
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