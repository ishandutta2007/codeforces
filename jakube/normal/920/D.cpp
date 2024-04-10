#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, V;
    cin >> N >> K >> V;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    auto total = accumulate(a.begin(), a.end(), 0LL);
    if (total < V) {
        cout << "NO" << '\n';
        return 0;
    }

    vector<bool> possible(K, false);
    possible[0] = true;
    vector<vector<int>> with(K);

    for (int i = 0; i < N; i++) {
        vector<bool> poss2 = possible;
        int x = a[i] % K;
        for (int j = 0; j < K; j++) {
            if (!possible[j] && possible[(j - x + K) % K]) {
                poss2[j] = true;
                with[j] = with[(j - x + K) % K];
                with[j].push_back(i);
            }
        }
        possible = poss2;
    }

    if (!possible[V % K]) {
        cout << "NO" << endl;
        return 0;
    }

    auto S = with[V % K];
    cout << "YES" << '\n';
    if (S.empty()) {
        for (int i = 1; i < N; i++) {
            if (a[i] == 0) continue;
            cout << (a[i] + K - 1) / K << " " << i + 1 << " " << 1 << '\n';
            a[0] += a[i];
            a[i] = 0;
        }

        if (V)
            cout << V / K << " 1 2\n";
    } else {
        vector<bool> vis(N, false);
        for (int x : S) {
            vis[x] = true;
            if (x != S[0] && a[x]) {
                cout << (a[x] + K - 1) / K << " " << x + 1 << " " << S[0] + 1 << '\n';
                a[S[0]] += a[x];
                a[x] = 0;
            }
        }
        int no = -1;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                if (no < 0) {
                    no = i;
                } else if (a[i]) {
                    cout << (a[i] + K - 1) / K << " " << i + 1 << " " << no + 1 << '\n';
                    a[no] += a[i];
                    a[i] = 0;
                }
            }
        }
        if (no == -1) {
            no = S[0] == 1 ? 2 : 1;
        }
        if (a[S[0]] < V) {
            cout << (V - a[S[0]]) / K << " " << no + 1 << " " << S[0] + 1 << '\n';
        }
        if (a[S[0]] > V) {
            cout << (a[S[0]] - V) / K << " " << S[0] + 1 << " " << no + 1 << '\n';
        }
    }
}