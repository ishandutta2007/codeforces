#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
const int LOCAL = 0;
int N, M;
vector<int> paths[5000];
int dist[5000][5000];
vector<int> v(3);
int target = -1;
void bfs(int idx, int s) {
    for(int i = 0; i < N; i++) dist[idx][i] = 1e9;
    dist[idx][s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(auto to : paths[now]) {
            if(chmin(dist[idx][to], dist[idx][now] + 1)) {
                que.push(to);
            }
        }
    }
}

void ask() {
    for(int i = 0; i < 3; i++) {
        cout << v[i] + (1 - LOCAL) << " ";
    }
    cout << endl;
    for(int i = 0; i < 3; i++) {
        if(v[i] == target) exit(0);
    }
    if(LOCAL) {
        cerr << "target: " << target << " -> ";
        if(target == -1) target = 0;
        target = paths[target][0];
        cerr << target << endl;
    } else {
        cin >> target;
        target--;
    }
    for(int i = 0; i < 3; i++) {
        if(v[i] == target) exit(0);
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    for(int i = 0; i < N; i++) {
        bfs(i, i);
    }
    int maxival = 1e9;
    for(int i = 0; i < N; i++) {
        int tmpval = 0;
        for(int j = 0; j < N; j++) {
            chmax(tmpval, dist[i][j]);
        }
        if(chmin(maxival, tmpval)) {
            v[0] = v[1] = v[2] = i;
        }
    }
    ask();
    for(int t = 0; t < N; t++) {
        for(int i = 0; i < 3; i++) {
            bool exist = false;
            for(auto to : paths[v[i]]) {
                if(to == target) exist = true;
            }
            if(exist) {
                v[i] = target;
                ask();
            }
        }
        vector<int> u(3);
        for(int i = 0; i < 3; i++) {
            if(paths[target].size() > i) {
                u[i] = paths[target][i];
            } else {
                u[i] = target;
            }
        }
        sort(u.begin(), u.end());
        for(int i = 0; i < 3; i++) {
            bfs(i, u[i]);
        }
        int nowval = 1e9;
        vector<int> query(3);
        vector<int> idx(3);
        vector<int> tmp(3);
        for(int i = 0; i < 3; i++) {
            idx[i] = i;
        }
        do {
            int tmpval = 0;
            for(int i = 0; i < 3; i++) {
                tmp[i] = v[i];
                for(auto to : paths[v[i]]) {
                    if(dist[idx[i]][to] < dist[idx[i]][tmp[i]]) tmp[i] = to;
                }
                tmpval += dist[idx[i]][tmp[i]];
            }
            if(chmin(nowval, tmpval)) swap(query, tmp);
        } while(next_permutation(idx.begin(), idx.end()));
        swap(query, v);
        ask();
    }
    return 0;
}