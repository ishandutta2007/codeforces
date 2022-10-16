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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
vector<int> pathes[200500];
vector<int> children[200500];
int parent[200500];
int root = 1;
int xdepth;
int depth[200050];
int dp[200050];
bool valid[200050];
int validnum;

void initialize(int now, int nowdepth) {
    depth[now] = nowdepth;
    for(int i = 0; i < pathes[now].size(); i++) {
        int to = pathes[now][i];
        if(to == parent[now]) continue;
        children[now].push_back(to);
        parent[to] = now;
        initialize(to, nowdepth + 1);
    }
}

void validation(int now, int depth) {
    //cerr << "VALIDATION: " << now << " " << depth << endl;
    if(depth == 0) {
        valid[now] = true;
        return;
    }
    for(int i = 0; i < children[now].size(); i++) {
        int to = children[now][i];
        validation(to, depth - 1);
    }
}

int search(int now) {
    int tmp = -1;
    dp[now] = 0;
    if(valid[now]) dp[now]++;
    int ans = -1;
    bool nowisvalid = true;
    for(int i = 0; i < children[now].size(); i++) {
        int to = children[now][i];
        tmp = search(to);
        if(tmp != -1) ans = tmp;
        if(dp[to] * 2 > validnum) nowisvalid = false;
        dp[now] += dp[to];
    }
    if(ans != -1) return ans;
    if((validnum - dp[now]) * 2 > validnum) nowisvalid = false;
    if(nowisvalid) return now;
    else return -1;
}

void del(int now) {
    if(now == root) return;
    valid[now] = false;
    for(int i = 0; i < children[now].size(); i++) {
        int to = children[now][i];
        del(to);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        pathes[a].push_back(b);
        pathes[b].push_back(a);
    }
    parent[root] = 0;
    initialize(root, 0);
    cout << "d 1" << endl;
    cin >> xdepth;
    if(xdepth == 0) {
        cout << "! 1" << endl;
        return 0;
    }
    cout << "s 1" << endl;
    int initial_s;
    cin >> initial_s;
    validation(initial_s, xdepth - 1);
    root = initial_s;
    parent[root] = 0;
    while(true) {
        int ans = 0;
        validnum = 0;
        for(int i = 1; i <= N; i++) {
            if(!valid[i]) continue;
            //cerr << "VALID: " << i << endl;
            validnum++;
            if(ans == 0) ans = i;
            else ans = -1;
        }
        if(ans > 0) {
            cout << "! " << ans << endl;
            return 0;
        }
        int query = search(root);
        //cerr << N << " " << validnum << endl;
        cout << "d " << query << endl;
        int len;
        cin >> len;
        if(len == 0) {
            cout << "! " << query << endl;
            return 0;
        }
        if(xdepth == depth[query] + len) {
            cout << "s " << query << endl;
            int oldroot = root;
            cin >> root;
            del(oldroot);
            parent[root] = 0;
            continue;
        } else {
            int p = parent[query];
            for(int i = 0; i < children[p].size(); i++) {
                if(children[p][i] == query) {
                    children[p].erase(children[p].begin() + i);
                    break;
                }
            }
            del(query);
        }
    }
    return 0;
}