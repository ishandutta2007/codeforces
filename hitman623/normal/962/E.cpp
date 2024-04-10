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
int n,lr=hell,rr=-hell,lb=hell,rb=-hell;
vector<pair<int,char>> v;
void solve(){
    cin>>n;
    v.resize(n);
    rep(i,0,n){
        cin>>v[i].x>>v[i].y;
        if(v[i].y!='B'){
            lr=min(lr,v[i].x);
            rr=max(rr,v[i].x);
        }
        if(v[i].y!='R'){
            lb=min(lb,v[i].x);
            rb=max(rb,v[i].x);
        }
    }
    int ans=max(0LL,rb-lb)+max(0LL,rr-lr);
    int h=0;
    while(h<n and v[h].y!='P') h++;
    if(h==n){
        cout<<ans<<endl;
        return;
    }
    int f3=v[h].x,r=0,b=0,lastr=f3,lastb=f3,lastp=f3,mxr=0,mxb=0;
    rep(i,h+1,n){
        if(v[i].y!='B'){
            mxr=max(mxr,v[i].x-lastr);
            lastr=v[i].x;
        }
        if(v[i].y!='R'){
            mxb=max(mxb,v[i].x-lastb);
            lastb=v[i].x;
        }
        if(v[i].y=='R'){
            r++;
        }
        if(v[i].y=='B'){
            b++;
        }
        if(v[i].y=='P'){
            ans-=max(0LL,mxr+mxb-v[i].x+lastp);
            mxr=mxb=r=b=0;
            lastp=v[i].x;
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