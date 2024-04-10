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
// [(y+p-1)/p]=x/p
// p<y
// [x-p+1,x]
const int n=1000001;
int t[2*n];
void build(){
    for(int i=n-1;i>0;--i) t[i]=min(t[i<<1],t[i<<1|1]);
}
void modify(int p,int val){
    for(t[p+=n]=val;p>1;p>>=1) t[p>>1]=min(t[p],t[p^1]);
}
int query(int l,int r){
    int res=hell;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1) res=min(res,t[l++]);
        if(r&1) res=min(res,t[--r]);
    }
    return res;
}
int p[1000001],dp2[1000001];
void solve(){
    memset(t,1,sizeof t);
    memset(dp2,1,sizeof dp2);
    for(int i=2;i<=1000000;++i){
        if(p[i]==0){
            for(int j=2*i;j<=1000000;j+=i){
                p[j]=1;
                t[j+n]=min(t[j+n],j-i+1);
            }
        }
    }
    build();
    memset(p,0,sizeof p);
    for(int i=2;i<=1000000;++i){
        if(p[i]==0){
            for(int j=2*i;j<=1000000;j+=i){
                p[j]=1;
                dp2[j]=min(dp2[j],query(j-i+1,j));
            }
        }
    }
    int x;
    cin>>x;
    cout<<dp2[x]<<endl;
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