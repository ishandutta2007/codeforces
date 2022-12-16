#include <bits/stdc++.h>
using namespace std;

int n;
int b[200001];
vector<int> adj[200001];
int64_t mx[200001];

int64_t findMx(int x) {
    if (mx[x] != -1) return mx[x];
    int64_t out = b[x];

    if (x-b[x] >= 0) {
        cout << x << ' ' << x-b[x] << endl;
        out += findMx(x-b[x]);
    }
    mx[x] = out;
    return out;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];

    unordered_map<int, int64_t> outp;
    int64_t out = 0;
    for (int i = 0; i < n; i++) {
        b[i] -= i;
        if (outp.find(b[i]) == outp.end()) {
            outp[b[i]] = b[i]+i;
        } else {
            outp[b[i]] += b[i]+i;
        }
        out = max(out, outp[b[i]]);
    }
    cout << out << endl;
}