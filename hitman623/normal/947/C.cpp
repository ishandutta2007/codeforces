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
int trie[10000006][2],f[10000006],node=1,bits=30;
void add(int x){
    int cur=1,cnt=0;
    while(cnt<=bits){
        int b=(x>>(bits-cnt))&1;
        if(trie[cur][b]){
            cur=trie[cur][b];
            f[cur]++;
        }
        else{
            trie[cur][b]=++node;
            cur=node;
            f[cur]++;
        }
        cnt++;
    }
}
int query(int x){
    int cur=1,cnt=0,ans=0;
    while(cnt<=bits){
        int b=(x>>(bits-cnt))&1;
        if(trie[cur][b] && f[trie[cur][b]]){
            cur=trie[cur][b];
        }
        else{
            cur=trie[cur][!b];
            ans+=(1<<(bits-cnt));
        }
        cnt++;
    }
    return ans;
}
void del(int x){
    int cur=1,cnt=0;
    while(cnt<=bits){
        int b=(x>>(bits-cnt))&1;
        cur=trie[cur][b];
        f[cur]--;
        cnt++;
    }
}
int n,a[300005],p[300005];
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }    
    rep(i,0,n){
        cin>>p[i];
        add(p[i]);
    }
    rep(i,0,n){
        int d=query(a[i]);
        cout<<d<<" ";
        del(a[i]^d);
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