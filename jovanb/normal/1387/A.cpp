#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld res[100005];
pair <ll, int> sta[100005];
vector <pair <int, int>> graf[100005];
bool visited[100005];

const int INF = 1000000000;

ld mora = -INF;
vector <int> vec;

void fail(){
    cout << "NO";
    exit(0);
}

bool isti(ld a, ld b){
    return abs(a-b) < 0.00001;
}

void dfs(int v){
    visited[v] = 1;
    vec.push_back(v);
    for(auto g : graf[v]){
        int c = g.first;
        int tr = g.second;
        if(visited[c]){
            if(sta[c].first + sta[v].first == 0 && sta[c].second + sta[v].second != tr) fail();
            else if(sta[c].first + sta[v].first){
                if(isti(mora, -INF)) mora = 1.0*(tr-sta[c].second-sta[v].second)/(sta[c].first+sta[v].first);
                if(!isti((sta[v].first+sta[c].first)*mora+sta[c].second+sta[v].second, tr)) fail();
            }
            continue;
        }
        sta[c].first = -sta[v].first, sta[c].second = tr-sta[v].second;
        dfs(c);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
        graf[b].push_back({a, c});
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            mora = -INF;
            sta[i] = {1, 0};
            vec.clear();
            dfs(i);
            if(isti(mora, -INF)){
                vector <int> g;
                for(auto c : vec){
                    if(sta[c].first) g.push_back(-sta[c].second/(1.0*sta[c].first));
                }
                sort(g.begin(), g.end());
                if(!g.empty()) mora = g[g.size()/2];
                else mora = 0;
                for(auto c : vec) res[c] = mora*sta[c].first + sta[c].second;
            }
            else{
                for(auto c : vec) res[c] = mora*sta[c].first + sta[c].second;
                for(auto c : vec){
                    for(auto g : graf[c]){
                        int v = g.first, tr = g.second;
                        if(!isti(tr, mora*(sta[c].first+sta[v].first)+sta[v].second+sta[c].second)) fail();
                    }
                }
            }
        }
    }
    cout << "YES\n";
    for(int i=1; i<=n; i++){
        cout << res[i] << " ";
    }
    return 0;
}