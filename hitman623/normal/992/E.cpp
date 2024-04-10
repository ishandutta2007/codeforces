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
int n,q,a[200005];
ll seg[800005];
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
ll query(int node,int start,int end,int l,int r){
    if(l<=start && r>=end) return seg[node];
    if(r<start || l>end) return 0;
    int mid=(start+end)>>1;
    return query(node<<1,start,mid,l,r)+query(node<<1|1,mid+1,end,l,r);
}
void update(int node,int start,int end,int x,int val){
    if(start==end){
        a[x]=val;
        seg[node]=val;
        return;
    }
    int mid=(start+end)>>1;
    if(start<=x && x<=mid) update(node<<1,start,mid,x,val);
    else update(node<<1|1,mid+1,end,x,val);
    seg[node]=seg[node<<1]+seg[node<<1|1];
}
int query2(int node,int start,int end,ll val){
    if(start==end) return start;
    int mid=(start+end)>>1;
    if(seg[node<<1]>=val) return query2(node<<1,start,mid,val);
    else return query2(node<<1|1,mid+1,end,val-seg[node<<1]);
}
void solve(){
    cin>>n>>q;
    rep(i,0,n){
        cin>>a[i];
    }
    build(1,0,n-1);
    rep(i,0,q){
        int x,y;
        cin>>x>>y;
        x--;
        update(1,0,n-1,x,y);
        if(a[0]==0){
            cout<<1<<endl;
            continue;
        }
        ll cur=a[0];
        int idx=0,f=0;
        do{
            idx=query2(1,0,n-1,2*cur);
            cur=query(1,0,n-1,0,idx);
            if(cur==2*a[idx]){
                f=1;
                cout<<idx+1<<endl;
                break;
            }
        }while(cur<=hell and idx<n-1);
        if(!f){
            cout<<-1<<endl;
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