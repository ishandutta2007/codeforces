#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

const ll BIG = 999999999;
vector<int> ans;
vector<set<int> > adj;
vector<int> nums;
map<int, int> adjn; // list of pairs; first index is num, second is number of pairs.
// sorting needed which is why its pairs and not ints

void remove(pair<int, int> it) {
    int d1 = it.first;
    int d2 = *(adj[d1].begin());
    adj[d1].erase(d2);
    adj[d2].erase(d1);
    ans[d2] += ans[d1];
    ans[d1] = 0;
    it.second = BIG;
    adjn[d1]--;
    adjn[d2]--;
    if(adjn[d2] == 1) remove(*(adjn.find(d2)));
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n;
        int anser = n*n-n;
        ans.push_back(0);
        adj.push_back(set<int>());
        adjn[0] = BIG;
        for(int i = 0; i < n; i++) {
            ans.push_back(1);
            adj.push_back(set<int>());
            adjn[i+1] = 0;
        }
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
            adjn[x]++;
            adjn[y]++;
        }
        for(auto it : adjn) {
            if(it.second == 1) remove(it);
        }
        for(int i = 1; i <= n; i++) {
            anser -= ((ans[i])*(ans[i])-ans[i])/2;
        }
        cout << anser << '\n';
        vector<int>().swap(ans);
        vector<set<int> >().swap(adj);
        map<int, int>().swap(adjn);
    }
}