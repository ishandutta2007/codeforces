#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 3e5+7;
int P[N];
int F(int x) {
    return x==P[x]?x:P[x] = F(P[x]);
}
int unite(int a,int b){
    a = F(a);
    b = F(b);
    if (a==b)
        return 0;
    P[a] = b;
    return 1;
}
vector<int> G[N];
int tin[N],tout[N],timer = 0;
#define is_par(a,b) (tin[a]<=tin[b] && tout[b]<=tout[a])
void dfs(int v,int par){
    tin[v] = ++timer;
    P[v] = par;
    for(int to:G[v]){
        if (to==par)
            continue;

        dfs(to,v);
    }
    tout[v] = timer;
}
int col[N];

pair<int,int> calc(int v,int par){
    pair<int,int> ret = {0,0};
    for(int to:G[v]){
        if (to==par)
            continue;
        pair<int,int> got =calc(to,v);
        ret.first+=got.first;
        ret.second+=got.second;
    }
    ret.first+=ret.second/2;
    ret.second = ret.second&1;
    if (col[v]==0){
        ret.first+=ret.second;
        ret.second = 0;
    }
    if (col[v]==1)
        ret.second = 1;

    return ret;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        P[i] = i;
    for(int i = 1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        if (unite(x,y))
            G[x].push_back(y),G[y].push_back(x);
    }
    dfs(1,1);
    int q;
    cin>>q;
    vector<vector<int> > ans;
    while(q--){
        int a,b;
        cin>>a>>b;
        vector<int> c1,c2;
        while(1){
            c1.push_back(a);
            col[a]^=1;
            if (is_par(a,b))
                break;
            a = P[a];
        }
        while(1){
            c2.push_back(b);
            col[b]^=1;
            if (is_par(b,a))
                break;
            b = P[b];
        }
        c2.pop_back();
        reverse(all(c2));
        for(int to:c2)
            c1.push_back(to);
        ans.push_back(c1);
    }
    int flag = 0;
    for(int i = 1;i<=n;++i){
        if (col[i])
            flag = 1;
    }
    if (flag==0){
        cout<<"YES\n";
        for(vector<int> path:ans){
            cout<<path.size()<<endl;
            for(int to:path)
                cout<<to<<' ';
            cout<<endl;
        }
    }
    else{
        cout<<"NO\n";

        pair<int,int> got = calc(1,1);
        cout<<got.first+got.second<<endl;

    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--)
        solve();
}