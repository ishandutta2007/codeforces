#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, sol;
int pos[MAXN];
vector <int> v[MAXN];

bool solve (int x, int rod) {
    pos[x] = x;
    vector <int> ch;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        if (solve(sus, x)) ch.push_back(sus);
    }
    if (ch.empty()) return 1;
    sol += ch.size() * 2;
    for (int i = 1; i < ch.size(); i++) {
        pos[ch[i - 1]] = ch[i];
    }
    pos[ch.back()] = x;
    pos[x] = ch[0];
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if (solve(1, 0)) {
        int sus = v[1].back();
        swap(pos[1], pos[sus]);
        sol += 2;
    }
    cout << sol << endl;
    for (int i = 1; i <= n; i++) cout << pos[i] << " ";
    return 0;
}