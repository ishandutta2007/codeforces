#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

vector <pair <int, int>> graf[100005];
int sz[100005];
ll dole[100005];
ll gore[100005];

int n;

bool good(int x){
    while(x){
        if(x%10 != 4 && x%10 != 7) return 0;
        x /= 10;
    }
    return 1;
}

void dfs2(int v, int parent){
    for(auto par : graf[v]){
        int c = par.first;
        if(c == parent) continue;
        int val = par.second;
        if(val){
            gore[c] = n - sz[c];
        }
        else{
            gore[c] = gore[v] + dole[v] - dole[c];
        }
        dfs2(c, v);
    }

}

void dfs1(int v, int parent){
    vector <int> vec;
    sz[v] = 1;
    for(auto par : graf[v]){
        int c = par.first;
        if(c == parent) continue;
        dfs1(c, v);
        int val = par.second;
        if(val){
            vec.push_back(sz[c]);
        }
        else vec.push_back(dole[c]);
        sz[v] += sz[c];
    }
    for(auto c : vec) dole[v] += c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    for(int i=1; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(good(c)){
            c = 1;
        }
        else c = 0;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    dfs1(1, 0);
    dfs2(1, 0);
    ll res = 0;
    for(int i=1; i<=n; i++){
        res += (gore[i]+dole[i])*(gore[i]+dole[i]-1);
    }
    cout << res;
    return 0;
}