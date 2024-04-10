#include <bits/stdc++.h>
using namespace std;

struct Truck {
    int s, f, c, r;
};
istream& operator>>(istream& is, Truck& truck) {
    is >> truck.s >> truck.f >> truck.c >> truck.r;
    truck.s--;
    truck.f--;
    return is;
}

bool check(Truck const& truck, long long V, vector<int> const& a) {
    int remaining = truck.r;
    long long cur = V;
    for (int i = truck.s + 1; i <= truck.f; i++) {
        long long needed = (long long)(a[i] - a[i-1]) * truck.c;
        if (cur >= needed) {
            cur -= needed;
        } else if (remaining && V >= needed) {
            cur = V - needed;
            remaining--;
        } else {
            return false;
        }
    }
    return true;
}

long long find_min(Truck const& truck, long long L, vector<int> const& a) {
    if (check(truck, L, a))
        return L;

    // L = not possible
    long long R = std::numeric_limits<long long>::max() / 2; // possible
    while (L + 1 < R) {
        long long M = (L + R) / 2;
        if (check(truck, M, a))
            R = M;
        else
            L = M;
    }
    return R;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector<Truck> trucks(m);
    for (auto& truck : trucks)
        cin >> truck;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(trucks.begin(), trucks.end(), std::default_random_engine(seed));
    
    long long minV = 0;
    for (auto truck : trucks) {
        minV = find_min(truck, minV, a);
    }
    cout << minV << '\n';
}