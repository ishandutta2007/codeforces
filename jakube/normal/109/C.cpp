#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    bool lucky;
};

vector<vector<Edge>> adj;

long long result = 0;

struct Result {
    long long lucky_pairs;
    long long unlucky_pairs;
    long long lucky_singles;
    long long unlucky_singles;
};

Result count(int v, int par) {
    Result res = {0, 0, 0, 1};

    for (auto next : adj[v]) {
        if (next.to == par) continue;
        
        auto rec = count(next.to, v);
        if (next.lucky) {
            rec.lucky_singles += rec.unlucky_singles;
            rec.unlucky_singles = 0;
            rec.lucky_pairs += rec.unlucky_pairs;
            rec.unlucky_pairs = 0;
        }

        result += 2 * res.lucky_pairs * (rec.lucky_singles + rec.unlucky_singles);
        result += 2 * res.unlucky_pairs * rec.lucky_singles;
        result += 2 * res.lucky_singles * (rec.lucky_pairs + rec.unlucky_pairs);
        result += 2 * res.unlucky_singles * rec.lucky_pairs;
        // l r l
        result += res.lucky_singles * rec.lucky_singles * (res.lucky_singles - 1);
        result += res.lucky_singles * rec.lucky_singles * res.unlucky_singles;
        result += res.lucky_singles * rec.unlucky_singles * (res.lucky_singles - 1);
        result += res.unlucky_singles * rec.lucky_singles * (res.unlucky_singles - 1);
        result += res.unlucky_singles * rec.lucky_singles * res.lucky_singles;
        // r l r
        result += rec.lucky_singles * res.lucky_singles * (rec.lucky_singles - 1);
        result += rec.lucky_singles * res.lucky_singles * rec.unlucky_singles;
        result += rec.lucky_singles * res.unlucky_singles * (rec.lucky_singles - 1);
        result += rec.unlucky_singles * res.lucky_singles * (rec.unlucky_singles - 1);
        result += rec.unlucky_singles * res.lucky_singles * rec.lucky_singles;

        res.lucky_pairs += (res.lucky_singles + res.unlucky_singles) * rec.lucky_singles;
        res.lucky_pairs += res.lucky_singles * (rec.lucky_singles + rec.unlucky_singles);
        res.lucky_pairs += rec.lucky_pairs;
        res.unlucky_pairs += res.lucky_singles * rec.unlucky_singles;
        res.unlucky_pairs += rec.lucky_singles * res.unlucky_singles;
        res.unlucky_pairs += rec.unlucky_pairs;
        res.lucky_singles += rec.lucky_singles;
        res.unlucky_singles += rec.unlucky_singles;
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    adj.resize(n);

    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        bool lucky = true;
        while (w) {
            lucky &= (w % 10 == 4 || w % 10 == 7);
            w /= 10;
        }
        adj[u].push_back({v, lucky});
        adj[v].push_back({u, lucky});
    }

    count(0, -1);

    cout << result << endl;

    return 0;
}