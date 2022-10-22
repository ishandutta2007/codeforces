#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<int> primes;

void eratosthenes() {
    vector<bool> vis(400, false);
    for (int i = 2; i < 400; i++) {
        if (!vis[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < 400; j += i) {
                vis[j] = true;
            }
        }
    }
}

vector<int> decompose(int a) {
    if (a == 0) exit(0);

    vector<int> result;
    for (auto p : primes) {
        if (a % p == 0) {
            result.push_back(p);
        }

        while (a % p == 0) {
            a /= p;
        }
    }

    if (a > 1) result.push_back(a);

    return result;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;

    eratosthenes();
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        if (n == 2) {
            cout << "2 0\n";
            continue;
        }

        vector<int> p(n, 0);
        vector<int> act_degree(n, 0);

        for (int i = 0; i < n; i++) act_degree[i] = graph[i].size();

        queue<int> bfs;
        bfs.push(0);

        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();

            for (auto u : graph[v]) {
                if (u != p[v]) {
                    p[u] = v;
                    bfs.push(u);
                }
            }
        }

        // find a node with only leaves
        int special_v = -1;
        for (int v = 0; v < n; v++) {
            if (act_degree[v] == 1) {
                continue;
            }

            bool found = true;
            for (auto u : graph[v]) {
                if (u != p[v] && act_degree[u] != 1) {
                    found = false;
                    break;
                }
            }

            if (found) {
                special_v = v;
                break;
            }
        }

        int possib_val = act_degree[special_v] - 1 + (special_v == 0 ? 1 : 0);

        // Faster version
        vector<int> possible_primes = decompose(possib_val);
        auto new_primes = decompose(possib_val + 1);
        for (auto p : new_primes) possible_primes.push_back(p);

        // Slower version
        // vector<int> possible_gcds;
        // for (int i = 2; i <= n; i++) {
        //     if ((possib_val % i == 0) || ((possib_val + 1) % i == 0)) {
        //         possible_gcds.push_back(i);
        //     }
        // }

        vector<int> results(n + 1, 0);
        vector<int> degree(n, 0);
        vector<int> curr_degree(n, 0);
        for (auto possib_gcd : possible_primes) {
            // cout << "T " << possib_gcd << "\n";
            for (int i = 0; i < n; i++) {
                degree[i] = act_degree[i];
                curr_degree[i] = act_degree[i];
            }

            queue<int> nodes;

            for (int u = 1; u < n; u++) if (degree[u] == 1) nodes.push(u);
            
            int current_gcd = 0;
            bool achievable = true;
            while (!nodes.empty()) {
                
                int v = nodes.front();
                nodes.pop();
                // cout << "UU " << current_gcd << " " << v << " " << curr_degree[v] << "\n";

                if (v == 0) {
                    // Faster version
                    int new_gcd = gcd(curr_degree[v], current_gcd);
                    if (new_gcd != 1 && results[new_gcd] != 1) {
                        results[new_gcd] = 1;
                    }

                    // Slower version
                    // if (gcd(curr_degree[v], current_gcd) == possib_gcd) {
                    //     results[possib_gcd] = 1;
                    // }

                    break;
                }

                if (gcd(curr_degree[v], current_gcd) % possib_gcd == 0) {
                    current_gcd = gcd(curr_degree[v], current_gcd);
                    curr_degree[p[v]]--;
                } else if (gcd(curr_degree[v] - 1, current_gcd) % possib_gcd != 0) {
                    break;
                } else {
                    current_gcd = gcd(curr_degree[v] - 1, current_gcd);
                }

                degree[p[v]]--;
                if ((degree[p[v]] == 1 && p[v] != 0) || (degree[p[v]] == 0 && p[v] == 0)) nodes.push(p[v]);
            }
        }

        results[1] = 1;
        for (int i = 0; i < n - 1; i++) {
            results[1] *= 2;
            if (results[1] >= MOD) results[1] -= MOD;
        }

        for (int i = 2; i <= n; i++) {
            if (results[i] == 1) results[1]--;
            if (results[1] == -1) results[1] += MOD;
        }

        for (int i = 1; i <= n; i++) cout << results[i] << " ";
        cout << "\n";
    }
}