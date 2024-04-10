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
int n,a[100005],b[100005];
set<int> s,s2;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        b[i]=a[i];
    }
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    rep(i,0,n-1){
        s.insert(a[i+1]-a[i]);
    }
    if(sz(s)>10){
        cout<<-1<<endl;
        return;
    }
    for(auto d:s){
        s2.insert(d);
        s2.insert(d-1);
        s2.insert(d+1);
        s2.insert(d-2);
        s2.insert(d+2); 
    }
    s=s2;
    int cnt=0,ans=hell,f;
    for(auto d:s){
        rep(i,0,n){
            a[i]=b[i];
        }
        cnt=0;
        f=1;
        rep(i,1,n){
            if(a[i]==a[i-1]+d+1){
                cnt++;
                a[i]--;
            }
            else if(a[i]==a[i-1]+d-1){
                cnt++;
                a[i]++;
            }
            else if(a[i]!=a[i-1]+d){
                f=0;
                break;
            }
        }
        if(f) ans=min(ans,cnt);
        cnt=1;
        f=1;
        rep(i,0,n){
            a[i]=b[i];
        }
        a[0]--;
        rep(i,1,n){
            if(a[i]==a[i-1]+d+1){
                cnt++;
                a[i]--;
            }
            else if(a[i]==a[i-1]+d-1){
                cnt++;
                a[i]++;
            }
            else if(a[i]!=a[i-1]+d){
                f=0;
                break;
            }
        }
        if(f) ans=min(ans,cnt);
        cnt=1;
        f=1;
        rep(i,0,n){
            a[i]=b[i];
        }
        a[0]++;
        rep(i,1,n){
            if(a[i]==a[i-1]+d+1){
                cnt++;
                a[i]--;
            }
            else if(a[i]==a[i-1]+d-1){
                cnt++;
                a[i]++;
            }
            else if(a[i]!=a[i-1]+d){
                f=0;
                break;
            }
        }
        if(f) ans=min(ans,cnt);
    }
    if(ans!=hell){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
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