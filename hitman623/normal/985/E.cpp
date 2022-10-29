#include <bits/stdc++.h>

#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          unordered_map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,d,a[500005];
const int N=500005;
int t[2*N];
void modify(int p,int val){
    for(t[p+=n+1]=val;p>1;p>>=1) t[p>>1]=t[p]+t[p^1];
}
int query(int l,int r){
    if(l>r) return 0;
    int res=0;
    for(l+=n+1,r+=n+2;l<r;l>>=1,r>>=1){
        if(l&1) res+=t[l++];
        if(r&1) res+=t[--r];
    }
    return res;
}
void solve(){
    cin>>n>>k>>d;
    rep(i,0,n){
        cin>>a[i];
    }
    sort(a,a+n);
    modify(n,1);
    for(int i=n-k;i>=0;i--){
        if(a[i+k-1]-a[i]>d) continue;
        int l=i+k,r=upper_bound(a,a+n,a[i]+d)-a;
        modify(i,!!query(l,r));
    }
    if(query(0,0)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
signed main(){
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}