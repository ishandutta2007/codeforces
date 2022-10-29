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
int n,k,l[200005],a[200005],ans,p[200005];
unordered_map<int,int> f;
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
        p[i]=a[i];
        if(i){
            p[i]+=p[i-1];
        }
        f[p[i]]=i;
    }
    int g=n;
    for(int i=n-1;i>=0;--i){
        if(a[i+1]>1) g=i+1;
        l[i]=g;
    }
    rep(i,0,n){
        int P=a[i],cur=i;
        vector<pair<int,pii>> v;
        while(cur<n){
            if(P%k==0){
                v.pb({P/k,{cur,l[cur]-1}});
            }
            cur=l[cur];
            if(P>1LL*1e17/a[cur]) break;
            P*=a[cur];
        }
        int h=0;
        if(i) h=p[i-1];
        for(auto j:v){
            int d=j.x;
            if(f.count(h+d) and f[h+d]>=j.y.x and f[h+d]<=j.y.y){
                ans++;
            }
        }
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