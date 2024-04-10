#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 3e5+7;
int dist[N],A[N],B[N];
pair<int,int> P[N];
void solve(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    for(int i = 1;i<=n;++i)
        cin>>B[i];
    int last = n;
    memset(dist,-1,sizeof(dist));
    dist[n] = 0;
    queue<int> Q;
    Q.push(n);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        int mx = v-A[v];
        for(int i = mx;i<=last;++i){
            if (dist[i+B[i]]==-1){
                dist[i+B[i]] = dist[v]+1;
                P[i+B[i]] = {v,i};
                Q.push(i+B[i]);
            }
        }
        last = min(last,mx);
        if (dist[v+B[v]]==-1){
            dist[v+B[v]] = dist[v]+1;
            P[v+B[v]] = {v,v};
            Q.push(v+B[v]);
        }
    }
    if (dist[0]==-1){
        cout<<"-1\n";
    }
    else{
        cout<<dist[0]<<endl;
        vector<int> ans;
        int x = 0;
        while(x!=n){
            ans.push_back(P[x].second);
            x = P[x].first;
        }
        reverse(all(ans));
        for(int to:ans)
            cout<<to<<' ';
        cout<<endl;
    }

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}