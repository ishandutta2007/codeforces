#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 300002;
set<int> st;
int mkd[MAXN];
bool taken[MAXN];
vector<vector<pii>> g;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    int k;
    int d;
    cin >> n >> k >> d;
    int a;
    for(int i = 0; i < k; ++i){
        cin >> a;
        a--;
        st.insert(a);
    }
    g.resize(n);
    int x, y;
    for(int i = 0; i < n - 1; ++i){
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(make_pair(y, i));
        g[y].push_back(make_pair(x, i));
    }
    queue<pii> q;
    for(auto t: st){
        q.push(make_pair(t, 0));
        mkd[t] = t + 1;
    }
    vector<int> ans;
    while(!q.empty()){
        pii p = q.front();
        int ver = p.first;
        int dist = p.second;
        q.pop();
        for(int i = 0; i < g[ver].size(); ++i){
            int ves = g[ver][i].first;
            int edge_idx = g[ver][i].second;
            if(mkd[ves] == 0){
                mkd[ves] = mkd[ver];
                q.push(make_pair(ves, dist + 1));
            }else{
                if(mkd[ves] != mkd[ver] && !taken[edge_idx]){
                    taken[edge_idx] = true;
                    ans.push_back(edge_idx + 1);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        if(i){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
    return 0;
}