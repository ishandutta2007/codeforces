#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef pair<int, int> P;
typedef vector<int> Node;
typedef vector<Node> Graph;

int main(){
    int N, M, K;
    while(cin >> N >> M >> K) {
        Graph G(N);
        REP(i, M) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        map<P, set<int>> forbid;
        REP(i, K) {
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--; c--;
            forbid[P(a, b)].insert(c);
        }
        queue<P> que;
        static int dist[3000][3000];
        static int back[3000][3000];
        memset(dist, 0x3f, sizeof(dist));
        dist[0][0] = 0;
        que.push(P(0, 0));
        bool answer = false;
        while(!que.empty()) {
            int a = que.front().first;
            int b = que.front().second;
            que.pop();
            if(b == N - 1) {
                // output
                answer = true;
                vector<int> route;
                route.push_back(b);
                while(a != 0) {
                    route.push_back(a);
                    // a, b = back[a][b], a
                    int tmp = a;
                    a = back[a][b];
                    b = tmp;
                }
                route.push_back(0);
                reverse(route.begin(), route.end());
                cout << route.size() - 1<< endl;
                REP(i, route.size()) {
                    cout << route[i] + 1;
                    if(i == route.size() - 1) {
                        cout << endl;
                    } else {
                        cout << " ";
                    }
                }
                break;
            }
            for(int c : G[b]) {
                if(c == b) continue;
                if(forbid[P(a, b)].count(c)) continue;
                if(dist[b][c] > dist[a][b] + 1) {
                    dist[b][c] = dist[a][b] + 1;
                    back[b][c] = a;
                    que.push(P(b, c));
                }
            }
        }
        if(!answer) cout << -1 << endl;
    }
    return 0;
}