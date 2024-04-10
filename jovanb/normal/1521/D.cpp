#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int sum;

vector <int> graf[100005];

vector <pair <int, int>> brisem;
vector <pair <int, int>> segs;

int k1[100005];
int k2[100005];

bool dfs(int v, int p){
    int cnt = 0;
    vector <int> moze;
    for(auto c : graf[v]){
        if(c == p) continue;
        if(dfs(c, v)){
            cnt++;
            moze.push_back(c);
        }
        else{
            brisem.push_back({v, c});
            segs.push_back({k1[c], k2[c]});
        }
    }
    if(cnt >= 2){
        sum--;
        int p = moze.back();
        moze.pop_back();
        int d = moze.back();
        moze.pop_back();
        if(k1[p] == p) k1[v] = k2[p];
        else k1[v] = k1[p];
        if(k1[d] == d) k2[v] = k2[d];
        else k2[v] = k1[d];
        for(auto c : moze){
            brisem.push_back({v, c});
            segs.push_back({k1[c], k2[c]});
        }
        moze.clear();
        return 0;
    }
    k1[v] = k2[v] = v;
    if(cnt >= 1){
        int p = moze.back();
        moze.pop_back();
        if(k1[p] == p) k1[v] = k2[p];
        else k1[v] = k1[p];
        return 1;
    }
    sum++;
    return 1;
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) graf[i].clear();
    brisem.clear();
    segs.clear();
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    sum = 0;
    dfs(1, 0);
    segs.push_back({k1[1], k2[1]});
    cout << sum - 1 << "\n";
    for(int i=0; i<sum-1; i++){
        cout << brisem[i].first << " " << brisem[i].second << " " << segs[i].second << " " << segs[i+1].first << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}