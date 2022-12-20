#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

vector<int> adj[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i-a[i] >= 0) {
            adj[i-a[i]].pb(i);
        }
        if (i+a[i] < n) {
            adj[i+a[i]].pb(i);
        }
    }
    int odddist[n];
    for (int i = 0; i < n; i++) odddist[i] = 1e9;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            q.push(mp(0, i));
            odddist[i] = 0;
        }
    }

    while (!q.empty()) {
        pair<int, int> top = q.top(); q.pop();
        if (odddist[top.second] < top.first) continue;

        for (int nxt : adj[top.second]) {
            if (top.first+1 >= odddist[nxt]) continue;
            odddist[nxt] = top.first+1;
            q.push(mp(top.first+1, nxt));
        }
    }

    int evendist[n];
    for (int i = 0; i < n; i++) evendist[i] = 1e9;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            q.push(mp(0, i));
            evendist[i] = 0;
        }
    }

    while (!q.empty()) {
        pair<int, int> top = q.top(); q.pop();
        if (evendist[top.second] < top.first) continue;

        for (int nxt : adj[top.second]) {
            if (top.first+1 >= evendist[nxt]) continue;
            evendist[nxt] = top.first+1;
            q.push(mp(top.first+1, nxt));
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            if (odddist[i] == 1e9) cout << -1 << ' ';
            else cout << odddist[i] << ' ';
        } else {
            if (evendist[i] == 1e9) cout << -1 << ' ';
            else cout << evendist[i] << ' ';
        }
    }
    cout << endl;
}