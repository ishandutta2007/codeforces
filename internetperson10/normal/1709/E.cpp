#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> nums, sums, dep;
vector<vector<int>> adj;
vector<set<int>*> sets;

void dfs(int x, int par = -1) {
    if(par != -1) dep[x] = dep[par] + 1;
    sums[x] = nums[x];
    if(par != -1) sums[x] ^= sums[par];
    for(int ch : adj[x]) {
        if(ch == par) continue;
        dfs(ch, x);
    }
    return;
}

int check_out(int x) {
    vector<pair<int, set<int>*>> child_sets;
    int par_xor = 0;
    for(int ch : adj[x]) {
        if(dep[ch] < dep[x]) {
            par_xor = sums[ch];
            continue;
        }
        child_sets.push_back(make_pair((*sets[ch]).size(), sets[ch]));
    }
    if(child_sets.size() == 0) {
        sets[x] = new set<int>;
        (*sets[x]).insert(sums[x]);
        return 0;
    }
    sort(child_sets.rbegin(), child_sets.rend());
    sets[x] = child_sets[0].second;
    bool bad_path = false;
    for(int i = 1; i < child_sets.size(); i++) {
        for(int g : *(child_sets[i].second)) {
            if((*sets[x]).count(g ^ nums[x])) {
                bad_path = true;
            }
        }
        for(int g : *(child_sets[i].second)) {
            (*sets[x]).insert(g);
        }
    }
    if((*sets[x]).count(par_xor)) bad_path = true;
    if(bad_path) {
        (*sets[x]).clear();
        cerr << "Removed " << 1+x << '\n';
        return 1;
    }
    (*sets[x]).insert(sums[x]);
    return 0;
}

// Wait does it really hang bruh 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    nums.resize(n);
    sums.resize(n, 0);
    dep.resize(n);
    adj.resize(n);
    sets.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    vector<pair<int, int>> ord(n);
    for(int i = 0; i < n; i++) {
        ord[i] = {dep[i], i};
    }
    sort(ord.rbegin(), ord.rend());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += check_out(ord[i].second);
    }
    cout << ans << '\n';
}