#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int color[200500];
vector<int> pathes[200050];
int n, m;
bool clear = true;

void bfs(int from) {
    for(int i = 0; i < pathes[from].size(); i++) {
        int to = pathes[from][i];
        if(color[to] == color[from]) {
            clear = false;
            return;
        }
        if(color[to] == 0) {
            color[to] = -color[from];
            bfs(to);
        }
    }
}

int a[200050];
int b[200050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        pathes[a[i]].push_back(b[i]);
        pathes[b[i]].push_back(a[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            color[i] = 1;
            bfs(i);
        }
    }
    if(!clear) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 1; i <= m; i++) {
        if(color[a[i]] == -1) cout << 0;
        else cout << 1;
    }
    cout << endl;
    return 0;
}