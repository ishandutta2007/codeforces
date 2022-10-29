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
#define N           1001
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

int m,n,vis[N],ans=1;
int C[N][N],bell[N];
bitset<N> s[101],cur;
void pre(){
    rep(i,0,N){
        rep(j,0,i+1){
            if(i==0 or j==0) C[i][j]=1;
            else C[i][j]=(C[i-1][j]+C[i-1][j-1])%hell;
        }
    }
    bell[0]=1;
    rep(i,1,N){
        rep(j,0,i){
            bell[i]=(bell[i]+1LL*C[i-1][j]*bell[j])%hell;
        }
    }
}
void solve(){
    cin>>m>>n;
    rep(i,0,n){
        cin>>s[i];
    }
    pre();
    rep(i,0,m){
        if(vis[i]) continue;
        cur.set();
        rep(j,0,n){
            if(s[j][i]) cur&=s[j];
            else cur&=s[j].flip();
        }
        int cnt=0;
        rep(j,0,m){
            if(cur[j]){
                vis[j]=1;
                cnt++;
            }
        }
        ans=1LL*ans*bell[cnt]%hell;
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