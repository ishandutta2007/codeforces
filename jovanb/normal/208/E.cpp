#include <bits/stdc++.h>
using namespace std;

vector <int> graf[100005];
int depth[100005];
int in[100005];
int out[100005];
vector <int> vec[100005];
int par[100005][20];
int cnt;

void dfs(int v, int dpth){
    in[v] = ++cnt;
    vec[dpth].push_back(in[v]);
    depth[v] = dpth;
    for(int i=1; i<=18; i++){
        par[v][i] = par[par[v][i-1]][i-1];
    }
    for(auto c : graf[v]){
        dfs(c, dpth+1);
    }
    out[v] = ++cnt;
}

int pr(int v, int k){
    int cn=0;
    while(k){
        if(k & 1) v = par[v][cn];
        cn++;
        k >>= 1;
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> par[i][0];
        if(par[i][0]) graf[par[i][0]].push_back(i);
    }
    for(int i=1; i<=n; i++){
        if(!par[i][0]){
            dfs(i, 0);
            //cout << i << " ";
        }
    }
    int m;
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        int tr = depth[a];
        //cout << tr << endl;
        a = pr(a, b);
        if(a == 0){cout << "0 "; continue;}
        int x1 = in[a], x2 = out[a];
        int x = vec[tr].size();
        //cout << vec[tr][0] << " " << vec[tr][1] << endl;
        int l=1, r=x, mx=0;
        while(l <= r){
            int mid = (l+r)/2;
            if(vec[tr][mid-1] < x1){
                mx = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        l = 1;
        r = x;
        int mx2 = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(vec[tr][mid-1] <= x2){
                mx2 = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        //cout << x << endl;
        //cout << mx2 << " e " << mx << endl;
        cout << mx2-mx-1 << " ";
    }
    return 0;
}