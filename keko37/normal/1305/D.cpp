#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 1005;

int n;
int d[MAXN], gone[MAXN];
vector <int> v[MAXN], leaf;

int ask (int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

pi nadi () {
    memset(d, 0, sizeof d);
    leaf.clear();
    for (int i = 1; i <= n; i++) {
        if (gone[i]) continue;
        for (auto sus : v[i]) {
            if (!gone[sus]) d[i]++;
        }
        if (d[i] <= 1) leaf.push_back(i);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    while (1) {
        nadi();
        if (leaf.size() == 1) {
            cout << "! " << leaf[0] << endl;
            break;
        }
        int a = leaf[0], b = leaf[1];
        int c = ask(a, b);
        if (a == c || b == c) {
            cout << "! " << c << endl;
            break;
        }
        gone[a] = gone[b] = 1;
    }
    return 0;
}