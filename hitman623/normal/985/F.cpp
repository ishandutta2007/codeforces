#include <bits/stdc++.h>

#define int         long long
#define pb          emplace_back
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
int n,m,p=31,pre[200005],pres[200005];
string s;
vi f[26],hsh[26];
void solve(){
    cin>>n>>m;
    cin>>s;
    rep(i,0LL,n){
        f[s[i]-'a'].pb(i+1);
    }
    pre[0]=1;
    rep(i,1,n+1){
        pre[i]=(pre[i-1]*p)%hell;
    }
    pres[0]=1;
    rep(i,1,n+1){
        pres[i]=(pre[i]+pres[i-1])%hell;
    }
    rep(i,0,26){
        if(sz(f[i])==0) continue;
        hsh[i].resize(sz(f[i]));
        hsh[i][0]=f[i][0];
        rep(j,1,sz(f[i])){
            hsh[i][j]=(hsh[i][j-1]*p+f[i][j])%hell;
        }
    }
    while(m--){
        int x,y,len,s1=0,ss1=0,s2=0,ss2=0,d1=0,d2=0;
        cin>>x>>y>>len;
        rep(i,0,26){
            int cur1=0,cur2=0;
            int r=upper_bound(all(f[i]),x+len-1)-f[i].begin()-1,l=lower_bound(all(f[i]),x)-f[i].begin()-1;
            if(r>=0){
                cur1+=hsh[i][r];
                cur1=(cur1+hell-(pres[r-l-1]*(x-1))%hell)%hell;
            }
            if(l>=0){
                cur1=(cur1+hell-(hsh[i][l]*pre[r-l])%hell)%hell;
            }
            r=upper_bound(all(f[i]),y+len-1)-f[i].begin()-1,l=lower_bound(all(f[i]),y)-f[i].begin()-1;
            if(r>=0){
                cur2+=hsh[i][r];
                cur2=(cur2+hell-(pres[r-l-1]*(y-1))%hell)%hell;
            }
            if(l>=0){
                cur2=(cur2+hell-(hsh[i][l]*pre[r-l])%hell)%hell;
            }
            s1=(s1+cur1)%hell;
            s2=(s2+cur2)%hell;
            ss1=(ss1+cur1*cur1)%hell;
            ss2=(ss2+cur2*cur2)%hell;
            d1=(d1+cur1*(int)sqrt(cur1))%hell;
            d2=(d2+cur2*(int)sqrt(cur2))%hell;
        }
        if(s1==s2 and ss1==ss2 and d1==d2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0LL);
    cout.tie(0LL);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0LL;
}