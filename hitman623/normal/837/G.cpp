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
#define hell        1000000007LL
#define data        kuchbhi
#define N           75001
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,x1[N],x2[N],q;
struct data{
    int bsum,asum,y1sum,y2sum;
    data(){
        asum=0,bsum=0,y1sum=0,y2sum=0;
    }
    void print(){
        cout<<"a "<<asum<<endl;
        cout<<"b "<<bsum<<endl;
        cout<<"y1 "<<y1sum<<endl;
        cout<<"y2 "<<y2sum<<endl;
    }
};
data x1d[18][N];
data x2d[18][N];
data f[N];
pii x1sorted[18][N];
pii x2sorted[18][N];
void add(data &u,data v){
    u.asum+=v.asum;
    u.bsum+=v.bsum;
    u.y1sum+=v.y1sum;
    u.y2sum+=v.y2sum;
}
void build(int h,int l,int r){
    if(l==r){
        x1sorted[h][l].x=x1[l];
        x2sorted[h][l].x=x2[l];
        x1sorted[h][l].y=x2sorted[h][l].y=l;
        add(x1d[h][l],f[l]);
        add(x2d[h][l],f[l]);
    }
    else{
        int m=(l+r)>>1;
        build(h+1,l,m);
        build(h+1,m+1,r);
        merge(x1sorted[h+1]+l,x1sorted[h+1]+m+1,x1sorted[h+1]+m+1,x1sorted[h+1]+r+1,x1sorted[h]+l);
        merge(x2sorted[h+1]+l,x2sorted[h+1]+m+1,x2sorted[h+1]+m+1,x2sorted[h+1]+r+1,x2sorted[h]+l);
        for(int i=r;i>=l;i--){
            if(i<r) add(x1d[h][i],x1d[h][i+1]);
            add(x1d[h][i],f[x1sorted[h][i].y]);    
        }
        rep(i,l,r+1){
            if(i>l) add(x2d[h][i],x2d[h][i-1]);
            add(x2d[h][i],f[x2sorted[h][i].y]);
        }
    }
}
int query(int h,int l,int r,int a,int b,int val){
    if(r<a || l>b || b<a) return 0;
    if(a<=l && r<=b){
        int cur=x2d[h][r].asum*val+x2d[h][r].bsum;
        int d=upper_bound(x1sorted[h]+l,x1sorted[h]+r+1,make_pair(val,-hell))-x1sorted[h];
        if(d<=r) cur=cur-x1d[h][d].asum*val-x1d[h][d].bsum+x1d[h][d].y1sum;
        d=upper_bound(x2sorted[h]+l,x2sorted[h]+r+1,make_pair(val,-hell))-x2sorted[h]-1;
        if(d>=l) cur=cur-x2d[h][d].asum*val-x2d[h][d].bsum+x2d[h][d].y2sum;
        return cur;
    }
    int m=(l+r)>>1;
    return query(h+1,l,m,a,b,val)+query(h+1,m+1,r,a,b,val);
}
void solve(){
    cin>>n;
    rep(i,0,n) cin>>x1[i]>>x2[i]>>f[i].y1sum>>f[i].asum>>f[i].bsum>>f[i].y2sum;
    build(0,0,n-1);
    cin>>q;
    int last=0;
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        l--,r--;
        x=(x+last)%(hell-7);
        cout<<(last=query(0,0,n-1,l,r,x))<<endl;
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