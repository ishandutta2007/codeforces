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
int n,T,t[200005],a[200005],l,r,mx=0,mn=hell;
int curans=0,ans=0;
vector<pair<int,int>> v;
void solve(){
    cin>>n>>T;
    rep(i,0,n){
        cin>>a[i];
    }
    l=0,r=n-1;
    rep(i,0,n){
        cin>>t[i];
        mx=max(mx,t[i]);
        mn=min(mn,t[i]);
        t[i]-=T;
        curans+=a[i]*t[i];
        v.pb({t[i],a[i]});
        ans+=a[i];
    }
    sort(all(v));
    while(curans){
        if(curans<0){
            if(curans-v[l].x*v[l].y>=0){
                cout<<1.0l*(ans-(1.0l*curans/v[l].x));
                return;
            }
            else{
                curans-=v[l].x*v[l].y;
                ans-=v[l].y;
                l++;
            }
        }
        else{
            if(curans-v[r].x*v[r].y<=0){
                cout<<1.0l*(ans-(1.0l*curans/v[r].x));
                return;
            }
            else{
                curans-=v[r].x*v[r].y;
                ans-=v[r].y;
                r--;
            }
        }
    }
    cout<<1.0l*ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);
    solve();
    return 0;
}