#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef long long ll;

ll powers[63];
bool presence[63];
vector<tuple<ll, ll, char>> results;

void computePowers() {
    powers[0] = 1;
    presence[0] = false;
    for (int i = 1; i <= 62; i++) {
        presence[i] = false;
        powers[i] = powers[i - 1] * 2;
    }
}

ll findSize(ll x) {
    ll i = 0;
    while (powers[i] <= x) {
        i++;
    }
    return i;
}

vector<int> toBits(ll x) {
    ll k = findSize(x);
    vector<int> res(k);
    for (int i = 0; i < k; i++) {
        res[i] = x  % 2;
        x /= 2;
    }
    return res;
}

void print(ll x, ll y, int p, char c) {
    results.push_back(make_tuple(x * powers[p], y * powers[p], c));
    // cout << x * powers[p] << " " << c << " " << y * powers[p] << "\n";
}

void printResults() {
    cout << results.size() << "\n";
    for (auto [x, y, c] : results) {
        cout << x << " " << c << " " << y << "\n";
    }
}

ll makeProper(ll x, int p) {
    vector<int> bits = toBits(x);
    int prev = 0;
    int minDist = 10000;
    for (int i = 1; i < bits.size(); i++) {
        if (bits[i] == 1) {
            minDist = min(minDist, i - prev);
            prev = i;
        }
    }
    minDist--;
    if (minDist == 0) {
        return x;
    }
    for (int i = 0; i < minDist; i++) {
        print(x * powers[i], x * powers[i], p, '+');
    }
    print(x, x * powers[minDist], p, '+');
    return x * (1 + powers[minDist]);
}

bool isAlternating(ll x) {
    vector<int> bits = toBits(x);
    for (int i = 0; i < bits.size() - 1; i++) {
        if (bits[i] == 1 && bits[i + 1] == 1) return false;
    }
    return true;
}


int findPower(ll x) {
    int res = 0;
    while (x % 2 == 0) {
        res++;
        x /= 2;
    }
    return res;
}

void solve(ll x, int p) {
    // cout << "Solving " << x << " " << p << "\n";
    if (x == 0) return;
    if (x == 1) return;
    
    if (isAlternating(x)) {
        x = makeProper(x, p);
        solve(x, p);
        return;
    }

    ll y = x * 2;
    ll z = y ^ x;
    ll t = z + x;

    print(x, x, p, '+');
    print(y, x, p, '^');
    print(z, x, p, '+');

    ll u = t ^ (y * 2);
    ll v = t ^ (z * 2);

    if (u < v) {
        print(y, y, p, '+');
        print(t, y * 2, p, '^');
    } else {
        print(z, z, p, '+');
        print(t, z * 2, p, '^');
        u = v;
    }

    int uPower2 = findPower(u);
    solve(u / powers[uPower2], p + uPower2);
    vector<int> xBits = toBits(x);
    int xSize = findSize(x);
    for (int i = 0; i < xSize - uPower2 - 1; i++) {
        if (!presence[uPower2 + i + 1 + p]) {
            print(powers[uPower2 + i], powers[uPower2 + i], p, '+');
        }
        presence[uPower2 + i + 1 + p] = true;
    }
    for (int i = uPower2; i < xSize; i++) {
        if (xBits[i] == 1) {
            print(x, powers[i], p, '^');
            x ^= powers[i];
        }
    }

    solve(x, p);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    computePowers();
    /*
    int maxOps = -1;
    vector<int> maxInts;
    for (int n = 3; n <= 999999; n += 2) {
        results.clear();
        solve(n, 0);
        int size = results.size();
        if (size > maxOps) {
            maxInts.clear();
            maxOps = size;
            maxInts.push_back(n);
        } else if (size == maxOps) {
            maxInts.push_back(n);
        }
    }
    cout << "MaxOps " << maxOps << "\n";
    for (auto i : maxInts) {
        cout << i << " ";
    }
    */
    int n;
    cin >> n;
    solve(n, 0);
    printResults();
}