#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef vector<int> Node;
typedef vector<Node> Graph;
typedef long long LL;

int main(){
    int m, k, p;
    while(cin >> m >> k >> p) {
        Graph G(m);
        REP(i, m - 1) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        vector<long long> depth(m - 1, -1);
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int u = que.front(); que.pop();
            for(int v : G[u]) {
                if(v > 0 && depth[v - 1] == -1) {
                    depth[v - 1] = depth[u - 1] + 1;
                    que.push(v);
                }
            }
        }
        sort(depth.begin(), depth.end());
        reverse(depth.begin(), depth.end());

        LL cost = 0;
        int end = 0;
        int ans = 0;
        for(int i = 0; i < depth.size(); i++) {
            if(i > 0) {
                cost -= (end - (i - 1)) * depth[i - 1];
                cost += depth[i - 1];
                cost += (end - i) * depth[i];
            }
            while((end + 1) - i <= k && end < depth.size()) {
                LL ncost = cost + (depth[i] - depth[end]);
                if(ncost > p) break;
                end++;
                cost = ncost;
            }
            ans = max(ans, end - i);
        }

        cout << ans << endl;
    }
    return 0;
}