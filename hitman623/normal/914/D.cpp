#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi             map<int,int>
#define mii            map<int,pii>    
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;
int a[500005],n,t[1000005];
void build() {
    for (int i=n-1;i>0;--i) t[i]=__gcd(t[i<<1],t[i<<1|1]);
}
void update(int p, int value) { 
  for (t[p+=n]=value; p > 1; p >>= 1) t[p>>1] = __gcd(t[p],t[p^1]);
}

int query(int l, int r) {
    int res=0;
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res=__gcd(res,t[l++]);
        if (r&1) res =__gcd(res,t[--r]);
    }
    return res;
}
bool query2(int l,int r,int x){
    int lo=l-1,hi=r+1,L,R;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(query(l,mid)%x==0) lo=mid;
        else hi=mid;
    }
    return (query(lo+2,r)%x==0);
}
void solve()
{
    cin>>n;
    rep(i,0,n){
        cin>>t[i+n];
    }
    build();
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int l,r,x;
            cin>>l>>r>>x;
            if(query2(l-1,r-1,x)) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            int l,x;
            cin>>l>>x;
            update(l-1,x);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)
        solve();
    return 0;
}