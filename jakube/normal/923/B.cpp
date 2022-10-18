#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct VeniceSet {
    std::multiset<T> s;
    T water_level = 0;

    void add(T v) {
        s.insert(v + water_level);
    }

    void remove(T v) {
        s.erase(s.find(v + water_level));
    }

    void decrease_all(T v) {
        water_level += v;
    }

    T min() const {
        return *s.begin() - water_level;
    }

    int size() const {
        return s.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    vector<long long> T(n);
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
    
    VeniceSet<long long> vs;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        vs.add(V[i]);
        while (vs.size() && vs.min() <= T[i]) {
            sum += vs.min();
            vs.remove(vs.min());
        }
        sum += vs.size() * T[i];
        cout << sum << " ";
        vs.decrease_all(T[i]);
    }
    cout << endl;
}