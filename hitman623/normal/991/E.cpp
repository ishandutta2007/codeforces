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
string s;
int freq[10],n,dp[1<<20],ans;
bool valid(int mask){
    int cur=0;
    rep(i,0,10){
        int f=1;
        rep(j,0,freq[i]){
            if((mask>>cur)&1){
                if(f==0) return 0;
            }
            else f=0;
            cur++;
        }
    }
    return 1;
}  
int f;
void solve(){
    cin>>s;
    n=sz(s);
    sort(all(s));
    for(auto i:s){
        f|=(1<<(i-'0'));
        freq[i-'0']++;
    }
    dp[0]=1;
    rep(i,0,1<<n){
        if(!valid(i)) continue;
        int st=0; 
        int cnt=0,id=-1;
        rep(j,0,n){
            if((i>>j)&1){
                cnt++;
                id=j;
            }
        }
        if(cnt==1 and s[id]=='0'){
            continue;
        }
        int vis[10]={0};
        for(int j=n-1;j>=0;j--){
            if((i>>j)&1 and vis[s[j]-'0']==0){
                vis[s[j]-'0']=1;
                dp[i]+=dp[i^(1<<j)];
                st|=(1<<(s[j]-'0'));
            }
        }
        if(f==st){
            ans+=dp[i];
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