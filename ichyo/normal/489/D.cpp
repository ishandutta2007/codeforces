#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef vector<int> Node;
typedef vector<Node> Graph;

int main(){
    int n, m;
    while(cin >> n >> m){
        Graph G(n);
        Graph GR(n);

        set<pair<int, int>> s;

        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            GR[b].push_back(a);
            s.insert(make_pair(a, b));
        }

        Graph BG(n);
        for(auto p : s) {
            int u = p.first;
            int v = p.second;
            if(u > v) continue;
            if(!s.count(make_pair(v, u))) continue;
            BG[u].push_back(v);
            BG[v].push_back(u);
        }

        REP(i, n) sort(G[i].begin(), G[i].end());
        REP(i, n) sort(GR[i].begin(), GR[i].end());
        REP(i, n) sort(BG[i].begin(), BG[i].end());
        static int cnt1[3000][3000] = {};
        static int cnt2[3000][3000] = {};
        static int cnt3[3000][3000] = {};
#ifdef LOCAL
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        memset(cnt3, 0, sizeof(cnt2));
#endif
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < G[i].size(); j++) {
                for(int k = j + 1; k < G[i].size(); k++) {
                    int u = G[i][j], v = G[i][k];
                    cnt1[u][v]++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < GR[i].size(); j++) {
                for(int k = j + 1; k < GR[i].size(); k++) {
                    int u = GR[i][j], v = GR[i][k];
                    cnt2[u][v]++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < BG[i].size(); j++) {
                for(int k = j + 1; k < BG[i].size(); k++) {
                    int u = BG[i][j], v = BG[i][k];
                    cnt3[u][v]++;
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                /*
                printf("cnt1[%d][%d] = %d cnt2[%d][%d] = %d\n",
                        i, j, cnt1[i][j], i, j, cnt2[i][j]);
                        */
                ans += 1LL * cnt1[i][j] * cnt2[i][j] - cnt3[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}