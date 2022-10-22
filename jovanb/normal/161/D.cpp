#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 100000;
 
typedef long long ll;
 
vector <int> graf[MAXN+5];
int depth[MAXN+5];
int sz[MAXN+5];
bool bio[MAXN+5];
 
void dfs_size(int v, int p){
    sz[v] = 1;
    for(auto c : graf[v]){
        if(c == p || bio[c]) continue;
        dfs_size(c, v);
        sz[v] += sz[c];
    }
}
 
int ime[MAXN+5];
int ukm[MAXN+5];
 
int k;
ll res;
 
void dfs_depth(int v, int p, int d){
    ime[d]++;
    //cout << v << " na " << d << endl;
    for(auto c : graf[v]){
        if(!bio[c] && c != p) dfs_depth(c, v, d+1);
    }
}
 
int centroid(int v, int p, int ukup){
    for(auto c : graf[v]) if(c != p && !bio[c] && sz[c]*2 > ukup) return centroid(c, v, ukup);
    return v;
}
 
void decompose(){
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        dfs_size(v, 0);
        v = centroid(v, 0, sz[v]);
        ///cout << "sad je " << v << endl;
        for(int i=0; i<=min(k, sz[v]); i++){
            ime[i] = ukm[i] = 0;
        }
        ukm[0] = 1;
        for(auto c : graf[v]){
            if(bio[c]) continue;
            dfs_depth(c, v, 1);
            for(int j=0; j<=sz[c]; j++){
                if(k < j) break;
                if(k-j <= sz[v] && k-j >= 0) res += 1LL*ime[j]*ukm[k-j];
            }
            for(int j=0; j<=sz[c]; j++){
                ukm[j] += ime[j];
                ime[j] = 0;
            }
        }
        bio[v] = 1;
        for(auto c : graf[v]) if(!bio[c]) q.push(c);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
 
    int n;
    cin >> n >> k;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    decompose();
    cout << res << "\n";
    return 0;
}