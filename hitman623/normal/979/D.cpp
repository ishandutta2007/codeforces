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
int q,mp[100005];
vi trie[100005][2],f[100005];
int bits=18,node[100005];
void add(int x,int g){
    int cur=1,cnt=0;
    while(cnt<=bits){
        if(f[g][cur]){
            f[g][cur]=min(f[g][cur],x);
        }
        else{
            f[g][cur]=x;
        }
        int b=(x>>(bits-cnt))&1;
        if(trie[g][b][cur]){
            cur=trie[g][b][cur];
        }
        else{
            trie[g][b][cur]=++node[g];
            cur=node[g];
        }
        if(f[g][cur]){
            f[g][cur]=min(f[g][cur],x);
        }
        else{
            f[g][cur]=x;
        }
        cnt++;
    }
}
int query(int x,int g,int s){
    int cur=1,cnt=0,ans=0;
    while(cnt<=bits){
        ans*=2;
        int b=(x>>(bits-cnt))&1;
        if(trie[g][!b][cur] and f[g][trie[g][!b][cur]]<=s-x){
            cur=trie[g][!b][cur];
            if(b==0) ans++;
        }
        else if(trie[g][b][cur] and f[g][trie[g][b][cur]]<=s-x){
            cur=trie[g][b][cur];
            if(b==1) ans++;
        }
        else return -1;
        cnt++;
    }
    return ans;
}
void solve(){
    rep(i,1,100001){
        node[i]=1;
        trie[i][0].resize((bits+5)*((100005/i)+2));
        trie[i][1].resize((bits+5)*((100005/i)+2));
        f[i].resize((bits+5)*((100005/i)+2));
    }
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int u;
            cin>>u;
            if(mp[u]) continue;
            mp[u]=1;
            for(int j=1;j*j<=u;++j){
                if(u%j==0){
                    add(u,j);
                    if(u/j!=j){
                        add(u,u/j);
                    }
                }
            }
        }
        else{
            int x,k,s;
            cin>>x>>k>>s;
            if(x%k){
                cout<<-1<<endl;
                continue;
            }
            cout<<query(x,k,s)<<endl;
        }
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