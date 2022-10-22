#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99;
 
int n,m,Q,a[N],ql[N],qr[N],lazy[4*N];
ll ans[N],seg[N*4];
vector<int> q[N];
 
void shift(int ,int ,int );
 
ll Combine(ll u,ll v){
    return u+v;
}
ll query(int id,int L,int R,int l,int r){
    ll res=0;
    if(R<=l || r<=L) return 0;
    if(l<=L && R<=r){
        res+=seg[id];
        return res;
    }
    int mid=(L+R+1)>>1;
    shift(id, L, R);
    res+=query(id*2+0, L, mid, l, r);
    res+=query(id*2+1, mid, R, l, r);
    return res;
}
void add(int id,int L,int R,int l,int r,ll val){
    if(R<=l || r<=L) return ;
    if(l<=L && R<=r){
        lazy[id] += val;
        seg[id] += (R-L) * val;
        return ;
    }
    int mid=(L+R+1)>>1;
    shift(id, L, R);
    add(id*2+0, L, mid, l, r, val);
    add(id*2+1, mid, R, l, r, val);
    seg[id]=Combine(seg[id*2+0],seg[id*2+1]);
}
void shift(int id,int L,int R){
    int mid=(L+R+1) >> 1;
    lazy[id*2+0] += lazy[id];
    lazy[id*2+1] += lazy[id];
    seg[id*2+0] += 1ll * (mid-L) * lazy[id];
    seg[id*2+1] += 1ll * (R-mid) * lazy[id];
    lazy[id]=0;    
}
void do_it(){
    stack<int> s;
    f(i,0,N)
        q[i].clear();
    f(i,0,N*4)
        lazy[i]=seg[i]=0;
    f(i,0,Q)
        q[qr[i]].pb(i);
    f(i,1,n+1){
        while(s.size() && a[s.top()]<a[i]) s.pop();
        m=(s.size() ? s.top() : 0);
        if(m+1<i) add(1,1,n+1,m+1,i,1);
        s.push(i);
        f(j,0,q[i].size())
            ans[q[i][j]]+=query(1,1,n+1,ql[q[i][j]],qr[q[i][j]]+1);
    }
}
 
main(){
    cin>>n>>Q;
    f(i,1,n+1)
        gett(a[i]);
    f(i,0,Q) gett(ql[i]);
    f(i,0,Q) gett(qr[i]);
   
    do_it();
    reverse(a+1,a+n+1);
    f(i,0,Q){
        qr[i]=n+1-qr[i];
        ql[i]=n+1-ql[i];
        swap(qr[i],ql[i]);
    }
    do_it();
    f(i,0,Q)
        printf("%I64d ",ans[i]+qr[i]-ql[i]+1);
}