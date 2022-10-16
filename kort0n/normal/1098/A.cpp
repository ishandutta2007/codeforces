#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
ll s[100050];
ll a[100050];
int parent[100050];
vector<int> children[100050];
bool flag = true;

void bfs(int from){
    if(from == 1){
        for(int i = 0; i < children[1].size(); i++){
            bfs(children[1][i]);
        }
        return;
    }
    if(s[from] == -1){
        //s[from] = s[parent[from]];
        ll mini = INF;
        for(int i = 0; i < children[from].size(); i++){
            mini = min(mini, s[children[from][i]]);
        }
        if(mini == INF){
            mini = s[parent[from]];
        }
        s[from] = mini;
    }
    a[from] = s[from] - s[parent[from]];
    if(a[from] < 0){
        flag = false;
    }
    for(int i = 0; i < children[from].size(); i++){
        bfs(children[from][i]);
    }
    return;
}

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    parent[1] = 0;
    for(int i = 2; i <= n; i++){
        int in;
        cin >> in;
        parent[i] = in;
        children[in].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    a[1] = s[1];
    bfs(1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += a[i];
    }
    if(!flag){
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}